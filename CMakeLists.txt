cmake_minimum_required(VERSION 3.17)
project(DataStructWithC C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructWithC main.c LinearTable/SqList.c LinearTable/SqList.h header.h LinearTable/LinkList.h LinearTable/SLinkList.h LinearTable/LinkList.c LinearTable/SLinkList.c)
add_executable(LinearTable LinearTable/SqList.c LinearTable/SqList.h LinearTable/LinkList.h LinearTable/SLinkList.h LinearTable/LinkList.c LinearTable/SLinkList.c LinearTable/ListTest.c LinearTable/ListTest.h)