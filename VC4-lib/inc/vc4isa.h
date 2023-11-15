/*
 * VideoCore IV Instruction Set Architecture Library
 * For Use With VC4Dis (Name Pending)
 * 
 * MIT License
 * 
 * Copyright (c) 2023 Wyatt Whitfield
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#ifndef vc4isa_libh
#define vc4isa_libh

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "common.h"

typedef unsigned char byte;

// Structure defining the address where the instruction came from, the
// textual name, actual contents, and the length of the contents, as well
// as the arguments contained by the text`
struct instruction_node {
    unsigned int address;
    // The actual name is fixed
    char *name;
    byte *content;
    unsigned int content_length;
};

// Get the number of bytes in the next instruction
unsigned int instruction_length(unsigned char* input);

// Get the instruction node of the instruction being read in
struct instruction_node* next_instruction(unsigned char* input, unsigned int instruction_size);


#ifdef __cplusplus
}
#endif

#endif
