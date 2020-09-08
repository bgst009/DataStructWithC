cmake_minimum_required(VERSION 3.17)

project(List)

set(SRC_DIR LinkList/LinkList.h LinkList/LinkList.c LinkList/testReverseList.c ../Stack&&Queue/Stack/LinkStack/LinkStack.c ../Stack&&Queue/Stack/LinkStack/LinkStack.h)

add_executable(Test ${SRC_DIR})