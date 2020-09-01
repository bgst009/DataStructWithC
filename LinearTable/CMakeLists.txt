cmake_minimum_required(VERSION 3.17)

project(List)

set(SRC_DIR LinkList/LinkList.h LinkList/LinkList.c LinkList/testReverseList.c)

add_executable(Test ${SRC_DIR})