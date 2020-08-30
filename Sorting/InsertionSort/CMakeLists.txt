cmake_minimum_required(VERSION 3.17)

project(InsertionSort)

set(SRC_DIR header.h TestInsertionSort.c Helper.h InsertionSort.c InsertionSort.h)

add_executable(InsertionSort ${SRC_DIR})