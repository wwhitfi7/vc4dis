#ifndef INSTRUCTION_LOOKUP
#define INSTRUCTION_LOOKUP

#include "definitions.h"
#include <stddef.h>
#include <stdint.h>

// Get length of instruction contents based on first byte
size_t get_content_length (uint8_t *contents);

// Get a full instruction's contents based on size
instruction* lookup_instruction (uint8_t *contents, size_t length);

// Get the name of an instruction based on it's first halfword
char* lookup_name_16 (uint16_t first_hword);
char* lookup_name_32 (uint16_t first_hword);
char* lookup_name_48 (uint16_t first_hword);
char* lookup_name_80 (uint16_t first_hword);

#endif
