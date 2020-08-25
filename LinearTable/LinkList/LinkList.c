//
// Created by 14991 on 2020/8/22.
//

#include "LinkList.h"

void createListHead(LinkList *L, int n) {
    LNode *p;
    int i;
    //带头结点的单链表 L (L 就是头节点)
    *L = (LinkList) malloc(sizeof(LNode));
    (*L)->next = NULL;
    //初始化随机树种子
    srand(time(0));
    for (int j = 0; j < n; ++j) {
        p = (LNode *) malloc(sizeof(LNode));
        p->data = rand() % 100 + 1;//0-100;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void createListTail(LinkList *L, int n) {
    //r 为指向尾部的指针
    LNode *r;
    LNode *p;
    int i;
    //带头结点的单链表 L (L 就是头指针)
    *L = (LinkList) malloc(sizeof(LNode));
    (*L)->next = NULL;
    r = *L;
    //初始化随机树种子
    srand(time(0));
    for (int j = 0; j < n; ++j) {
        p = (LNode *) malloc(sizeof(LNode));
        p->data = rand() % 100 + 1;//0-100;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

bool GetElem_L(LinkList L, int i, ElemType *e) {
    //声明节点 p
    LNode *p;
    // 指向第一个节点
    p = L->next;

    //为第一个元素则直接返回
    if (i == 0) {
        *e = L->data;
        return true;
    }
    if (i < 1) {
        printf("\n i 值异常 \n");
        return false;
    }

    // j 计数器
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }

    //第 i 个元素不存在；
    if (!p || j > i) {
        return false;
    }
    //去除第 i 个元素
    *e = L->data;

    return p;
}

bool ListTraverse_L(LinkList *L) {
//    printf("\n ListTraverse_L \n");

    LNode *p;
    p = (*L)->next;
    //计数器
    int j = 0;

    while (p) {
        printf(" %d ", p->data);
        p = p->next;
        ++j;
        if (j % 20 == 0) {
            printf("\n");
        }
    }
}

bool ListDelete_L(LinkList L, int i, ElemType *e) {
    //声明节点 p
    LNode *p;
    // 指向第一个节点
    p = L->next;
    int j = 1;

    //looking for elem i
    while (j < i && p) {
        p = p->next;
        ++j;
    }

    // the i is not exist
    if (!p || j > i) {
        printf("\nNo such Elem!!!\n");
        return false;
    }

    //temp Node
    LNode *q = p->next;
    p->next = q->next;

    *e = q->data;
    //del node p
    free(q);

    return true;
}

bool ListInsert_L(LinkList L, int i, ElemType e) {
    //声明节点 p
    LNode *p;
    // 指向第一个节点
    p = L->next;
    int j = 1;

    //looking for elem i
    while (j < i && p) {
        p = p->next;
        ++j;
    }

    // the i is not exist
    if (!p || j > i) {
        printf("\nNo such Elem!!!\n");
        return false;
    }

    //creat a new Node of List
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}
