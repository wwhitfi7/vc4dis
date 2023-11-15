#include <stdlib.h>
#include "vc4isa.h"

// Perform a lookup on the instruction based on its value. 
struct instruction_node* next_instruction(byte* input, unsigned int instruction_size) {
    struct instruction_node* rval = malloc(sizeof(struct instruction_node));
    
    switch (instruction_size) {
    case 10:
        // Handle Vector80's here
    break;
    case 6:
        // Handle Vector48's and Scalar48's here
    break;
    case 4:
        // Handle Scalar 32's here
    break;
    case 2:
        // Handle Scalar 16's or data half-words here.
    break;
    }

    // TODO: Return this function. 
    return rval;
}
