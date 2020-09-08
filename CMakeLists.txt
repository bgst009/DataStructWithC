cmake_minimum_required(VERSION 3.17)
project(DataStructWithC C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructWithC main.c LinearTable/SqList/SqList.c LinearTable/SqList/SqList.h header.h LinearTable/LinkList/LinkList.h LinearTable/SLinkList/SLinkList.h LinearTable/LinkList/LinkList.c LinearTable/SLinkList/SLinkList.c)
add_executable(LinearTable LinearTable/SqList/SqList.c LinearTable/SqList/SqList.h LinearTable/LinkList/LinkList.h LinearTable/SLinkList/SLinkList.h LinearTable/LinkList/LinkList.c LinearTable/SLinkList/SLinkList.c LinearTable/LinkList/ListTest.c LinearTable/LinkList/ListTest.h)
add_executable(Tree Tree/test.c Tree/test.h Tree/header.h Tree/BinaryTree/BinaryTree.c Tree/BinaryTree/BinaryTree.h Tree/BinaryTree/LinkQueue/LinkQueue.h Tree/BinaryTree/LinkQueue/LinkQueue.c Tree/BinaryTree/TreeNode.h Tree/BinaryTree/BinarySearchTree.c Tree/BinaryTree/BinarySearchTree.h)
