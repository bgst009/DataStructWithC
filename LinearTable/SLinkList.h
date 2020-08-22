//
// Created by 14991 on 2020/8/22.
//

#ifndef DATASTRUCTWITHC_SLINKLIST_H
#define DATASTRUCTWITHC_SLINKLIST_H

#include "../header.h"

#define ListInitSize  100
#define ListIncrement  10
#define MAXSIZE 15
typedef int ElemType;
/*==================================== SLinkList ===========================*/
//线性表的静态单链表存储
typedef struct {
    ElemType data;
    int cur;
} component, SLinkList[MAXSIZE];

//InitList
bool InitList_SL(SLinkList space);

//若备用链表非空，则返回分配的节点的小标，否则返回 0
int Malloc_SL(SLinkList space);

//将小标为K的 空闲节点回收
void Free_SL(SLinkList space, int k);

//ListInsert
//在 L 中第 i 个元素前插入新的数据元素e
bool ListInsert_SL(SLinkList Space, int i, ElemType e);

//ListDelete
//在 L 中删除 第 i 个数据元素e
bool ListDel_SL(SLinkList Space, int i);

//初始条件：静态链表已经存在
//操作结果：返回 L 中数据元素的个数
int ListLength_SL(SLinkList space);

//操作结果：打印静态链表
bool ListTraverse_SL(SLinkList);

#endif //DATASTRUCTWITHC_SLINKLIST_H
