cmake_minimum_required(VERSION 3.17)
project(Sortings)
set(SRC_DIR InsertionSort/InsertionSort.h InsertionSort/InsertionSort.c SelectionSort/SelectionSort.h SelectionSort/SelectionSort.c ShellSort/ShellShort.h ShellSort/ShellShort.c MergeSort/MergeSort.h MergeSort/MergeSort.c TestSortAlgs/header.h TestSortAlgs/test.c TestSortAlgs/test.h TestSortAlgs/SortTestHelper.h)
add_executable(test ${SRC_DIR})