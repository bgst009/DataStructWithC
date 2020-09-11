cmake_minimum_required(VERSION 3.17)
project(DataStructWithC C)

set(CMAKE_C_STANDARD 11)

set(stack_src_dir Stack&&Queue/Stack/ArrayStack.c)

add_executable(StackTest ${stack_src_dir})