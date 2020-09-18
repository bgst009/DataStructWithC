cmake_minimum_required(VERSION 3.1)
project(DataStructWithC C)

set(CMAKE_C_STANDARD 11)

set(stack_src_dir Stack&&Queue/Stack/ArrayStack.c)
set(tree_src_dir
        Tree/Binary-Search-Tree/BST.c
        Tree/Binary-Search-Tree/BST.h
        Tree/include/c_def.h
        Tree/include/c_iterator.c
        Tree/include/t_stack.c
        Tree/include/c_stack.c
        Tree/include/c_memory.c
        Tree/include/c_vector.c
        Tree/include/c_algo.c
        Tree/include/c_pair.c
        Tree/include/c_queue.c
        Tree/include/c_list.c
        Tree/include/c_function.c)
set(STLstack_src_dir
        Tree/include/c_def.h
        Tree/include/c_iterator.c
        Tree/include/t_stack.c
        Tree/include/c_stack.c
        Tree/include/c_memory.c
        Tree/include/c_vector.c
        Tree/include/c_algo.c
        Tree/include/c_pair.c
        Tree/include/c_function.c)
add_executable(StackTest ${stack_src_dir})
add_executable(TreeTest ${tree_src_dir})
add_executable(STLStackTest ${tree_src_dir})