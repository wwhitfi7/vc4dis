#include "../inc/lookup.h"
#include "../inc/lang_patterns.h"

size_t get_content_length (uint8_t *contents)
{
    switch (*contents & vector_mask) {
        case  vector_10:
            return 10;
            break;
        case  vector_6:
            return 6;
            break;
    }      
    if ((*contents & scalar_mask_first) == scalar_6) return 6; 
    switch (*contents & scalar_mask_second) {
        case scalar_4:
            return 4;
            break;
        case scalar_2:
            return 2;
            break;
    }
}
// Ignore the warning here - ALL bytes will match either scalar_4 or scalar_2
// as based on the value of their leftmost bit

