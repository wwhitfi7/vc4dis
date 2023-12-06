#ifndef INSTRUCTION_LOOKUP
#define INSTRUCTION_LOOKUP

#include "definitions.h"
#include <stddef.h>
#include <stdint.h>

// Get length of instruction contents based on first byte
size_t get_content_length (uint8_t *contents);

// Get a full instruction's contents based on size
instruction lookup_instruction (uint8_t *contents, size_t length);

#endif
