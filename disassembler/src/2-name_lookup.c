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
            return "ldm";
            break;
        case stm_reg:
            return "stm";
            break;
        case ldm_reg_pc:
            return "ldm_pc";
            break;
        case stm_reg_pc:
            return "stm_pc";
            break;
    }
    // Next, check the instruction against the first 5 and 8th bits
    switch (first_hword & ld_st_short_mask) {
        case ld_short:
            return "ld";
	    	break;
        case st_short:
            return "st";
	    	break;
    }
    // Next, check the instruction against the first 7 bits
    switch (first_hword & ld_st_short_offset_mask) {
        case ld_short_offset:
            return "ld";
            break;
        case st_short_offset:
            return "st";
            break;
    }
    // Next, check the first five bits 
    switch (first_hword & br_cond_add_mask) {
        case add_sp_offset:
            return "add";
            break;
        case br_cond_short_offset:
            return "br";
            break;
    }
    switch (first_hword & ld_st_reg_offset_mask) {
        case ld_reg_offset:
            return "ld";
            break;
        case st_reg_offset:
            return "st";
            break;
    }
    switch (first_hword & short_arithlog_mask) {
        case reg_reg_arithlog:
            return "regreg_placeholder";
            break;
        case reg_imd_arithlog:
            return "regimd_placeholder";
            break;
    }
    return "placeholder";
}

char* lookup_name_32 (uint16_t first_hword) {
    switch (first_hword & mem_mask_32_b) {
        case ld_cond_indx:
            return "ld";
	    	break;
        case st_cond_indx:
            return "st";
	    	break;
        case ld_cond_predec:
            return "ld";
	    	break;
        case st_cond_predec:
            return "st";
	    	break;
        case ld_cond_postinc:
            return "ld";
	    	break;
        case st_cond_postinc:
            return "st";
	    	break;
        case ld_16b_disp_reg24:
            return "ld";
	    	break;
        case st_16b_disp_reg24:
            return "st";
	    	break;
        case ld_16b_disp_sp:
            return "ld";
	    	break;
        case st_16b_disp_sp:
            return "st";
	    	break;
        case ld_16b_disp_pc:
            return "ld";
	    	break;
        case st_16b_disp_pc:
            return "st";
	    	break;
        case ld_16b_disp_r0:
            return "ld";
	    	break;
        case st_16b_disp_r0:
            return "st";
	    	break;
    } 
    switch (first_hword & mem_mask_32_b_12bd) {
        case ld_12b_disp:
            return "ld";
        case st_12b_disp:
            return "st";
    }
    if ((first_hword & reg_pc_16b_offset_mask) == reg_pc_16b_offset) return "add";
    switch (first_hword & word_arithlog_mask) {
        case reg_imd16_arithlog:
            return "reg_imd16_placeholder";
            break;
        case add_reg_reg_imd16:
            return "add";
            break;
    }
    if ((first_hword & word_arithlog_cond_mask) == cond_arithlog_2word_det)
        return "cond_arithlog_2word_placeholder";
    if ((first_hword & word_fop_mask) == word_fop_cond_det)
        return "fop_cond_det_placeholder";
    switch (first_hword & fp_int_conversion_mask) {
        case ftrunc_cond_det:
            return "ftrunc_cond_det";
            break;
        case floor_cond_det:
            return "floor_cond_det";
            break;
        case flts_cond_sign_det:
            return "flts_cond_sign_det";
            break;
        case flts_cond_usign_det:
            return "flts_cond_usign_det";
            break;
        // Processor control instructions can be tested with the same mask as
        // the floating point operation instructions, so they exist here
        case mov_pd_ra:
            return "mov";
            break;
        case mov_rd_pd:
            return "mov";
            break;
    }
    return "placeholder";
} 

char* lookup_name48 (uint16_t first_hword) {
    switch (first_hword & mem_mask_48b_full) {
        case jump_immed48:
            return "j";
            break;
        case branch_offset48:
            return "b";
            break;
        case jump_long_immed48:
            return "jl";
            break;
        case branch_long_offset48:
            return "bl";
            break;
    }
    if ((first_hword & mem_mask_48b_add) == add_reg_pc_offset48)
        return "add";
    switch (first_hword & mem_mask_48b_ldst) {
        case ld_reg_offset48:
			return "ld";
			break;
        case st_reg_offset48:
			return "st";
			break;
        case ld_reg_pc_offset48:
			return "ld";
			break;
        case st_reg_pc_offset48:
			return "st";
			break;
    }
    switch (first_hword & arithlog_mask_48b) {
        case arithlog_op_48b:
            return "arithlog_placeholder_48b";
            break;
        case arithlog_add_48b:
            return "add";
            break;
    }
    return "placeholder";
}
