/*
 * Disassembler Common Types
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

#ifndef disassembler_common_types
#define disassembler_common_types

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef uint8_t byte;

enum instruction_types {
    DATA=0,
    MATH_OP=1,
    LOGIC_OP=1,
    MEMORY_OP,
    COND_KNOWN_BRANCH,
    IMMED_KNOWN_BRANCH,
    COND_COMPUTED_BRANCH,
    IMMED_COMPUTED_BRANCH,
    INTERRUPT,
    FLOAT_OP,
};
typedef enum instruction_types itypes;

enum argument_types {
    CONDITION,
    OPERATION,
    FLOAT_OPERATION,
    DATA_WIDTH,
    REGISTER_REF,
    COMPUTED_OFFSET_2X,
    COMPUTED_OFFSET_4X,
    OFFSET_DIRECT,
    IMMEDIATE,

};
typedef enum argument_types atypes;

struct argument {
    atypes type;
    byte* content;
};

typedef struct argument argument;




#ifdef __cplusplus
}
#endif
#endif
