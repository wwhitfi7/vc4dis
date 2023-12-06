#include "../inc/lookup.h"
#include "../inc/instructions.h"
#include <stdint.h>

char* lookup_name_16 (uint16_t first_hword) {
    // First, check the instruction for a perfect match against a well-defined
    // instruction
    switch (first_hword) {
    case bkpt:
        return "breakpoint";
		break;
    case nop:
        return "no_operation";
		break;
    case sleep:
        return "sleep";
		break;
    case user:
        return "user_mode";
		break;
    case ei:
        return "enable_interrupts";
		break;
    case di:
        return "disable_interrupts";
		break;
    case cbclr:
        return "column_base_clear";
		break;
    case cbadd1:
        return "column_base_add1";
		break;
    case cbadd2:
        return "column_base_add2";
		break;
    case cbadd3:
        return "column_base_add3";
		break;
    case rti:
        return "return_from_interrupt";
		break;
    }
    // Next, check the instruction against the largest mask value:
    switch (first_hword & table_branch_16_mask) {
    case switch_b:
        return "switch_byte";
        break;
    case switch_s:
        return "switch_short";
        break;
    }
    // Next, check the instruction against the first 11 bits:
    switch (first_hword & swir_branch_ver_16_mask) {
    case swi_reg:
        return "software_interrupt_reg";
		break;
    case branch:
        return "branch_reg";
		break;
    case branch_long:
        return "branch_long_reg";
		break;
    case version:
        return "version";
		break;
    }
    // Next, check the instruction against the first 10 bits
    if ((first_hword & swi_u_mask) ==  swi_u) 
        return "software_interrupt_immed";
    // Next, check the instruction against the first 9 bits
    switch (first_hword & stack_registers_mask) {
    case ldm_reg:
        break;
    case stm_reg:
        break;
    case ldm_reg_pc:
        break;
    case stm_reg_pc:
        break;
    }
    return "placeholder";

}
