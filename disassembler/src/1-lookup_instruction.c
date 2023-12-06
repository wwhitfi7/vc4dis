#include "../inc/lookup.h"
#include <stdint.h>
#include <stdlib.h>

instruction *lookup_instruction(uint8_t *contents, size_t length) {
  // Per VideoCore IV Programmer's Manual - instructions can be treated as
  // sequences of 16-bit words, except for scalar48's. However, all
  // instructions, including scalar48's, begin with a single 16bit word.
  instruction *workingInstruction = malloc(sizeof(instruction));
  uint16_t first_halfword =
      ((uint16_t)contents[0]) + (((uint16_t)contents[1]) << 8);
  workingInstruction->name = lookup_name(first_halfword);
  workingInstruction->contents = contents;
  workingInstruction->content_len = length;
}
