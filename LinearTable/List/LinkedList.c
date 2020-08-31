//
// Created by bgst on 2020/8/31.
//
#include "../header.h"
#include "../list.h"

struct Node {
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L) {
    L->Next = NULL;
}
bool IsEmpty(List L) {
    return L->Next == NULL;
}
bool IsLast(Position P, List L) {
    return P->Next == NULL;
}
Position Find(ElementType X, List L) {
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;
    return P;
}
void Delete(ElementType X, List L) {
    Position P, TmpCell;
    P = Find(X, L);
    if (!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}
Position FindPrev(ElementType X, List L) {
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}
void Insert(ElementType X, Position P) {
    Position TmpCell;
    TmpCell = (Position) malloc(sizeof(Node));
    if (TmpCell == NULL) {
        printf("Node alloc failed");
        return;
    }

    TmpCell->Next = P->Next;
    TmpCell->Element = X;
    P->Next = TmpCell;
}
void DeleteList(List L) {
    Position P, Tmp;
    P = L->Next;
    L->Next == NULL;
    while (P != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}
Position Header(List L) {
    return L;
}
Position First(List L) {
    return L->Next;
}
Position Advance(Position P) {
    return P->Next;
}
ElementType Retrieve(Position P) {
    return P ? P->Element : -1;
}