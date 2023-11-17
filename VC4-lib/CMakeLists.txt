add_library(VC4-lib
    src/0-instruction_length.c)
target_include_directories(VC4-lib PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/common
    )
