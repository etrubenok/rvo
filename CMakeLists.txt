cmake_minimum_required(VERSION 3.28)
project(rvo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile commands for Cppcheck
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GOOGLE TEST SETUP
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Define the source files for Cppcheck to analyze
set(SOURCE_FILES
        main.cpp
        copyable_buffer.cpp
        bad_copy_buffer.cpp
        include/copyable_buffer.h
        include/bad_copy_buffer.h
)

add_executable(rvo ${SOURCE_FILES})

add_executable(rvo_test
        include/copyable_buffer.h
        include/bad_copy_buffer.h
        bad_copy_buffer.cpp
        bad_copy_buffer_test.cpp
        copyable_buffer.cpp
        copyable_buffer_test.cpp)
target_compile_definitions(rvo_test PRIVATE UNIT_TEST)
target_link_libraries(rvo_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(rvo_test)

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