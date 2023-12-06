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

// Includes
#include <stdint.h>

// Provides definitions of common data types in this program - instructions,
// arguments, etc.

// Enumeration of possible instructions
enum instruction_type {
    bkpt,
    halt, 
    sleep,
    user,
    enable_interrupts,
    disable_interrupts,
    col_base_clear,
    col_base_add_1,
    col_base_add_2,
    col_base_add_3,
    return_from_interrupt,
    software_interrupt,
    branch,
    branch_long,
    switch_b,
    switch_s,
    version,
    load_from_stack,
    store_to_stack,
    load,
    store,
    add_offset,
    branch_conditional,
    math_logic_op,
    add_cond_branch,
    math_logic_cond,
    fl_op,
    ftrunc_cond,
    floor,
    flts,
    fltu,
    proc_control_reg_mov,
    jump,
    jump_long,
    vector_op
};

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
    instruction_type type;
    unsigned int content_len;
    uint8_t *contents; // location of instruction in source binary's buffer
    char *name; // Null-terminated c-string naming the instruction
    unsigned int arg_len;
    arg *args; // Array of args
};
