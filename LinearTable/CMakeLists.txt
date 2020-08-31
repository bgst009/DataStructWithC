cmake_minimum_required(VERSION 3.17)

project(List)

set(SRC_DIR list.h List/LinkedList.c)

add_executable(Test ${SRC_DIR})