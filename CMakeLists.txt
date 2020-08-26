cmake_minimum_required(VERSION 3.17)
project(DataStructWithC C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructWithC main.c LinearTable/SqList/SqList.c LinearTable/SqList/SqList.h header.h LinearTable/LinkList/LinkList.h LinearTable/SLinkList/SLinkList.h LinearTable/LinkList/LinkList.c LinearTable/SLinkList/SLinkList.c)
add_executable(LinearTable LinearTable/SqList/SqList.c LinearTable/SqList/SqList.h LinearTable/LinkList/LinkList.h LinearTable/SLinkList/SLinkList.h LinearTable/LinkList/LinkList.c LinearTable/SLinkList/SLinkList.c LinearTable/LinkList/ListTest.c LinearTable/LinkList/ListTest.h)
add_executable(Stack Stack/Sq_Stack/Stack_test.c Stack/Sq_Stack/Stack_test.h Stack/Sq_Stack/Sq_Stack.c Stack/Sq_Stack/Sq_Stack.h Stack/LinkStack/LinkStack.c Stack/LinkStack/LinkStack.h Stack/LinkStack/LinkStack_test.c Stack/LinkStack/LinkStack_test.h Stack/test.c)
add_executable(Queue Queue/test.c Queue/LinkQueue/LinkQueue.c Queue/LinkQueue/LinkQueue.h Queue/SqQueue/SqQueue.c Queue/SqQueue/SqQueue.h Queue/header.h)
add_executable(Tree Tree/test.c Tree/test.h Tree/header.h Tree/BinaryTree/BinaryTree.c Tree/BinaryTree/BinaryTree.h Tree/BinaryTree/LinkQueue/LinkQueue.h Tree/BinaryTree/LinkQueue/LinkQueue.c)