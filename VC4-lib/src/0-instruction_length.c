#include "vc4isa.h"
unsigned int next_instruction_is(unsigned char* input)
{
        // Copy first byte of next instruction off the stack for decode
        unsigned char val = *input & 0xF8 ;
        switch (val) {
                case 0xF8:
                    return 10;
                case 0xF0:
                    return 6;
        }
        val = val & 0xF0;
        switch (val) {
                case 0xE0:
                    return 6;
        }
        val = val & 0x80;
        switch (val) {
                case 0x80:
                    return 4;
                case 0x00:
                    return 2;
        }
}
