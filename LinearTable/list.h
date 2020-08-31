//
// Created by bgst on 2020/8/31.
//

#ifndef MERGESORT_LIST_H
#define MERGESORT_LIST_H

struct Node;
typedef struct Node Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

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

#endif//MERGESORT_LIST_H
