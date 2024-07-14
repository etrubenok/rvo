cmake_minimum_required(VERSION 3.28)
project(rvo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
#set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fsanitize=address")


add_executable(rvo main.cpp
        copyable_buffer.cpp
        bad_copy_buffer.cpp)

#target_compile_options(rvo PRIVATE -O0)  # No optimizations