cmake_minimum_required(VERSION 3.17)

project(MergeSort)

set(SRC_DIR header.h Helper.h MergeSort.h MergeSort.c TestMergeSort.c InsertionSort.h InsertionSort.c)

add_executable(MergeSort ${SRC_DIR})