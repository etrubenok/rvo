cmake_minimum_required(VERSION 3.28)
project(rvo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Export compile commands for Cppcheck
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
#set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fsanitize=address")

# Define the source files for Cppcheck to analyze
set(SOURCE_FILES
        main.cpp
        copyable_buffer.cpp
        bad_copy_buffer.cpp
        include/copyable_buffer.h
        include/bad_copy_buffer.h
)

add_executable(rvo ${SOURCE_FILES})



# Define the command to run Cppcheck
add_custom_target(
        cppcheck
        COMMAND cppcheck
        --project=${CMAKE_BINARY_DIR}/compile_commands.json
        --enable=all
        --inconclusive
        --std=c++23
        --language=c++
        --inline-suppr
        --suppress=missingIncludeSystem
        -I ${CMAKE_SOURCE_DIR}/include
        -i ${CMAKE_BINARY_DIR}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running Cppcheck"
        VERBATIM
)

add_dependencies(rvo cppcheck)

#target_compile_options(rvo PRIVATE -O0)  # No optimizations