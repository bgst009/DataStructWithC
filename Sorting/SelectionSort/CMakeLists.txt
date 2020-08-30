cmake_minimum_required(VERSION 3.17)

project(SelectionSort)

SET(SRC_DIR TestSelectionSort.c SelectionSort.h SelectionSort.c  Helper.h header.h)

add_executable(SelectionSort ${SRC_DIR})