#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "vc4isa.h"

// Forward definition of functions to populate instruction_node based on input
void vector80_lookup(struct instruction_node* process, byte* input);
void vector48_lookup(struct instruction_node* process, byte* input);
void scalar48_lookup(struct instruction_node* process, byte* input);
void scalar32_lookup(struct instruction_node* process, byte* input);
void scalar16_lookup(struct instruction_node* process, byte* input);

// Perform a lookup on the instruction based on its value. 
struct instruction_node* next_instruction(byte* input, unsigned int instruction_size) {
    struct instruction_node* rval = malloc(sizeof(struct instruction_node));
    
    switch (instruction_size) {
    case 10:
        // Handle Vector80's here
        vector80_lookup(rval, input);
    break;
    case 6:
        // Handle Vector48's and Scalar48's here
        // Vector 48's will eval to 0xf0, scalar evals to 0xe0
        if ((input[0] & 0xf0) == 0xf0) {
            vector48_lookup(rval, input);
            return rval;
        } else {
            return rval;
            scalar48_lookup(rval, input);
        }
    break;
    case 4:
        // Handle Scalar 32's here
        scalar32_lookup(rval, input);
        return rval;
    break;
    case 2:
        // Handle Scalar 16's or data half-words here.
        scalar16_lookup(rval, input);
        return rval;
    break;
    }

    // TODO: Return this function. 
    return rval;
}


/* This function takes a pointer to an instruction_node and an array of input
 * bytes whose length is determined elsewhere in the library. It's not intended
 * for use outside of this library because there's no other way to determine w/
 * absolute certainty that the pointer to a byte[6] actually points to 6 bytes
 * in memory.
 *
 * Based on the value of the bytes given as input, this function modifies the
 * provided instruction_node's name, value, content, and eventually argument
 * nodes */
void scalar48_lookup(struct instruction_node* process, byte* input) {
    uint16_t i_hword;
    uint32_t d_word;

    // copy first 2 bytes into instruction halfword variable, last 4 into
    // data word variable
    memcpy(&i_hword, input, 2);
    memcpy(&d_word, (input+2), 4);

    switch (i_hword) {
    case 0xE000:
        process->name = "j";
        // TODO - Append arguments
    break;
    case 0xE100:
        process->name = "b";
        // TODO - Append arguments
    break;
    case 0xE200:
        process->name = "jl";
        // TODO - Append arguments
    break;
    case 0xE300:
        process->name = "bl";
        // TODO - Append arguments
    break;
    }

    if ((i_hword & 0xFFE0) == 0xE500) {
         process->name = "add";
    } 

    switch (i_hword & 0xFF00) {
    case 0xE600:

    break;
    case 0xE700:
        if (i_hword & 0x0020) {
            process->name = "st";    
        } else {
            process->name = "ld";    
        }
    break;
    }
    
    memcpy(process->content, input, 6);
    process->content_length = 6;


    return;
}
