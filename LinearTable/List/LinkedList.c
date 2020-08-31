//
// Created by bgst on 2020/8/31.
//
#include "header.h"
#include "list.h"

struct Node {
    ElementType Element;
    Position Next;
};
List InitList() {
    List list = (List) malloc(sizeof(Node));

    if (list == NULL) {
        printf("\nFailed to allocate\n");
        return NULL;
    }

    return list;
}
List MakeEmpty(List L) {
    DeleteList(L);
    L = (List) malloc(sizeof(Node));
    L->Next = NULL;
    return L;
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
    P = FindPrev(X, L);
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
    L->Next = NULL;
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
void createList_Head(List L, int n) {
    Node *node;
    //初始化随机树种子
    srand(time(0));
    for (int j = 0; j < n; ++j) {
        node = (Node *) malloc(sizeof(Node));
        node->Element = j;//0-100;
                          //        node->Element = rand() % 100 + 1;//0-100;
        node->Next = L->Next;
        L->Next = node;
    }
}

void createList_Tail(List L, int n) {
    //r 为指向尾部的指针
    Node *r;
    Node *p;
    int i;

    r = L;
    //初始化随机树种子
    srand(time(0));
    for (int j = 0; j < n; ++j) {
        p = (Node *) malloc(sizeof(Node));
        p->Element = j;//1-100;
                       //        p->Element = rand() % 100 + 1;//1-100;
        r->Next = p;
        r = p;
    }
    r->Next = NULL;
}

//操作结果：打印输出链表
bool ListTraverse(List L) {
    Node *node;
    node = L->Next;
    int j = 0;
    while (node) {
        printf(" %d ", Retrieve(node));
        node = node->Next;
        ++j;
        if (j % 20 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return true;
}