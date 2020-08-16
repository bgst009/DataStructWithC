//
// Created by 14991 on 2020/8/16.
//

#ifndef DATASTRUCTWITHC_SQLIST_H
#define DATASTRUCTWITHC_SQLIST_H


#include "../header.h"

#define ListInitSize  100
#define ListIncrement  10
#define MAXSIZE 20
typedef int ElemType;

// 线性表的顺序表示 静态
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqListStatic;

// 线性表的顺序表示 动态
typedef struct {
    ElemType *data;
    int length;
    int listSize;
} SqListDynamic;

//线性表的单链表存储结构
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
//InitList
bool InitList_Sq(SqListDynamic *L);

//随机产生 n 个元素的值，建立带表头节点的单链线性表L（头插法）
void createListHead(LinkList *L, int n);

//随机产生 n 个元素的值，建立带表头节点的单链线性表L（尾插法）
void createListTail(LinkList *L, int n);

//DestroyList
bool DestroyList_Sq(SqListDynamic *L);
//ClearList
bool ClearList_Sq(SqListDynamic *L);
//ListEmpty
bool ListEmpty_Sq(SqListDynamic L);

//ListLength
int ListLength_Sq(SqListDynamic L);
//GetElem
bool GetElem_Sq(SqListDynamic L, int i, ElemType *e);
//初始条件：线性表已经存在 1<=i<=ListLength(L)
//操作结果：用 e 返回 L 中第 i 个元素的值
bool GetElem_L(LinkList L, int i, ElemType *e);
//LocateElem
bool LocateElem_Sq(SqListDynamic L, ElemType e, int *index);
//PriorElem
bool PriorElem_Sq(SqListDynamic L, ElemType cur_e, ElemType *pre_e);
//NextElem
bool NextElem_Sq(SqListDynamic L, ElemType cur_e, ElemType *next_e);
//ListInsert
bool ListInsert_Sq(SqListDynamic *L, int i, ElemType e);
//初始条件：线性表已经存在 1<=i<=ListLength(L)
//操作结果：在 L 中第 i 个 位置前插入新的元素 e ， L的长度加一
bool ListInsert_L(LinkList L, int i, ElemType e);
//ListDelete
bool ListDelete_Sq(SqListDynamic *L, int i, ElemType *e);
//初始条件：线性表已经存在 1<=i<=ListLength(L)
//操作结果： 删除 L 中第 i 个 数据元素，用 额 返回其值 ， L 的长度减少 一
bool ListDelete_L(LinkList L, int i, ElemType *e);
//ListTraverse
bool ListTraverse_Sq(SqListDynamic L);

//test
void test_SqList();


#endif //DATASTRUCTWITHC_SQLIST_H
