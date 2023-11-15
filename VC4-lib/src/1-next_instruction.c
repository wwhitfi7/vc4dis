#include <stdlib.h>
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



void scalar48_lookup(struct instruction_node* process, byte* input) {
    unsigned short i_hword;
    unsigned int d_word;
    return;
}
