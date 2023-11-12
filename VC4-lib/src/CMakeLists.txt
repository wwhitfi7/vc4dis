set(CMAKE_EXPORT_COMPILE_COMMANDS)
add_library(VC4-isa 0-next_instruction_is.c)
target_include_directories(VC4-isa
    PUBLIC
    inc/)
