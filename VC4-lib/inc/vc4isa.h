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

#include <cstdbool>

enum instruction_type {      
        SCALAR16,
        SCALAR32,
        SCALAR48,
        VECTOR48,
        VECTOR80,
};

struct instruction_node {
        unsigned int address;
};

// Get the enumerated instruction type of the next instruction
instruction_type next_instruction_is(unsigned char* input);

// Get the instruction node of the instruction being read in


#ifdef __cplusplus
}
#endif

#endif
