cmake_minimum_required(VERSION 3.1)
project(DataStructWithC C)

set(CMAKE_C_STANDARD 11)

set(stack_src_dir Stack&&Queue/Stack/ArrayStack.c)
set(tree_src_dir Tree/Binary-Search-Tree/BST.c Tree/Binary-Search-Tree/BST.h)

add_executable(StackTest ${stack_src_dir})
add_executable(TreeTest ${tree_src_dir})