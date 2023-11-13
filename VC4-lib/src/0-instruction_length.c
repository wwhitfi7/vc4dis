#include "vc4isa.h"
unsigned short next_instruction_is(unsigned char* input)
{
        // Copy first byte of next instruction off the stack for decode
        unsigned char val = *input & 0xF8 ;
        switch (val) {
                case 0xF8:
                    return VECTOR80;
                case 0xF0:
                    return VECTOR48;
        }
        val = val & 0xF0;
        switch (val) {
                case 0xE0:
                    return SCALAR48;
        }
        val = val & 0x80;
        switch (val) {
                case 0x80:
                    return SCALAR32;
                case 0x00:
                    return SCALAR16;
        }
}