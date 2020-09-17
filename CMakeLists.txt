cmake_minimum_required(VERSION 3.1)
project(DataStructWithC C)

set(CMAKE_C_STANDARD 11)

set(stack_src_dir Stack&&Queue/Stack/ArrayStack.c)
set(tree_src_dir
        Tree/Binary-Search-Tree/BST.c
        Tree/Binary-Search-Tree/BST.h
        Tree/Stack/c_def.h
        Tree/Stack/c_iterator.c
        Tree/Stack/t_stack.c
        Tree/Stack/c_stack.c
        Tree/Stack/c_memory.c
        Tree/Stack/c_vector.c
        Tree/Stack/c_algo.c
        Tree/Stack/c_pair.c
        Tree/Stack/c_function.c)
set(STLstack_src_dir
        Tree/Stack/c_def.h
        Tree/Stack/c_iterator.c
        Tree/Stack/t_stack.c
        Tree/Stack/c_stack.c
        Tree/Stack/c_memory.c
        Tree/Stack/c_vector.c
        Tree/Stack/c_algo.c
        Tree/Stack/c_pair.c
        Tree/Stack/c_function.c)
add_executable(StackTest ${stack_src_dir})
add_executable(TreeTest ${tree_src_dir})
add_executable(STLStackTest ${tree_src_dir})