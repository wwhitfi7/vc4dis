/*

MIT License

Copyright (c) 2023 Wyatt Whitfield

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef DEFINITIONS
#define DEFINITIONS

// Includes
#include <stdint.h>

// Provides definitions of common data types in this program - instructions,
// arguments, etc.

// Enumeration of possible instruction categories

enum arg_type {
    condition_code,
    arim_log_code_4,
    arim_log_code_5,
    arim_log_code,
    register_ref,
    width_code,
    immediate,
};

// Typedefs here
typedef enum instruction_type instruction_type;
typedef enum arg_type arg_type;
typedef struct instruction instruction;
typedef struct arg arg;

struct arg {
    arg_type type;
    char *name; // Null-terminated c-string naming the argument
};

// Struct defs here
struct instruction {
    unsigned int content_len;
    uint8_t *contents; // location of instruction in source binary's buffer
    char *name; // Null-terminated c-string naming the instruction
    unsigned int arg_len;
    arg *args; // Array of args
};
#endif
