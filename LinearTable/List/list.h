//
// Created by bgst on 2020/8/31.
//

#ifndef MERGESORT_LIST_H
#define MERGESORT_LIST_H
#include "header.h"

struct Node;
typedef struct Node Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;


List InitList();
List MakeEmpty(List L);
bool IsEmpty(List L);
bool IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrev(ElementType X, List L);
void Insert(ElementType X, Position L);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
//随机产生 n 个元素的值，建立带表头节点的单链线性表L（头插法）
void createList_Head(List L, int n);

//随机产生 n 个元素的值，建立带表头节点的单链线性表L（尾插法）
void createList_Tail(List L, int n);

//操作结果：打印输出链表
bool ListTraverse(List L);
#endif//MERGESORT_LIST_H
