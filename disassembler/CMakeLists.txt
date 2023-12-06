add_executable(disassembler
    src/main.c
    src/0-get_instruction_length.c)
target_include_directories(disassembler PRIVATE 
    $(CMAKE_CURRENT_SOURCE_DIR)/inc
)
