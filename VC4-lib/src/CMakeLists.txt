include_directories(${GlobalDisassembler_SOURCE_DIR}/VC4-isa/inc)
set(CMAKE_EXPORT_COMPILE_COMMANDS)
add_library(VC4-isa 0-next_instruction_is.c)
