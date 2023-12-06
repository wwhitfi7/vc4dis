#ifndef LANG_PATTERNS
#define LANG_PATTERNS
enum length_encoding {
    vector_mask = 0xF8,
    vector_10 = 0xF8,
    vector_6 = 0xF0,
    scalar_mask_first = 0xF0,
    scalar_6 = 0xE0,
    scalar_mask_second = 0x80,
    scalar_4 = 0x80,
    scalar_2 = 0x00,
};
#endif
