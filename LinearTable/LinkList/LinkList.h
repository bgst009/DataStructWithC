//
// Created by bgst on 2020/8/22.
//

#ifndef DATASTRUCTWITHC_LINKLIST_H
#define DATASTRUCTWITHC_LINKLIST_H
#define ListInitSize 100
#define ListIncrement 10
typedef int ElemType;

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ===================================     Link List    ============================== */
//线性表的单链表存储结构
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//随机产生 n 个元素的值，建立带表头节点的单链线性表L（头插法）
void createListHead(LinkList *L, int n);

//随机产生 n 个元素的值，建立带表头节点的单链线性表L（尾插法）
void createListTail(LinkList *L, int n);

//初始条件：线性表已经存在 1<=i<=ListLength(L)
//操作结果：用 e 返回 L 中第 i 个元素的值
bool GetElem_L(LinkList L, int i, ElemType *e);

//初始条件：线性表已经存在 1<=i<=ListLength(L)
//操作结果：在 L 中第 i 个 位置前插入新的元素 e ， L的长度加一
bool ListInsert_L(LinkList L, int i, ElemType e);

//初始条件：线性表已经存在 1<=i<=ListLength(L)
//操作结果： 删除 L 中第 i 个 数据元素，用 额 返回其值 ， L 的长度减少 一
bool ListDelete_L(LinkList L, int i, ElemType *e);

//ListTraverse
//操作结果：打印输出链表
bool ListTraverse_L(LinkList *L);

bool IsEmpty(const LinkList L);

/**
 * 原地翻转链表
 * @param L 链表
 * @return LinkList
 */
LinkList ReverseList_L(LinkList L);
/**
 * 头插法翻转链表
 * @param L 链表
 * @return LinkList
 */
LinkList ReverseList_L_2(LinkList L);

/**
 * 逆序打印链表(递归)
 * @param L 链表
 */
void ReversePrint_Recursive(LinkList L);
/**
 * 逆序打印链表（栈）
 * @param L 链表
 */
void ReversePrint_Stack(LinkList L);

/**
 * 按顺序奇偶分成两个链表（第一个元素为序列号为 0 记作序号为偶数字的节点）
 * @param L 待拆链表
 * @param AB 用于返回两个链表
 */
void DepartList(LinkList L, LinkList AB[2]);

#endif//DATASTRUCTWITHC_LINKLIST_H
