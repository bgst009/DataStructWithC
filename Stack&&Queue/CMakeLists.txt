cmake_minimum_required(VERSION 3.17)
project(SQ)
set(CMAKE_C_STANDARD 11)
set(SRC_DIR DynamicArray/Array.c Stack/ArrayStack.c)
add_executable(SQ ${SRC_DIR})