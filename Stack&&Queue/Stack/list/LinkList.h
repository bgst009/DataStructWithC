//
// Created by bgst on 2020/8/22.
//

#ifndef DATASTRUCTWITHC_LINKLIST_H
#define DATASTRUCTWITHC_LINKLIST_H

typedef int ElemType;
//typedef char ElemType;

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

//循环双链表
typedef struct DNode {
    ElemType data;
    struct DNode *Prior;
    struct DNode *Next;
    int freq;
} DNode, *DLinkList;

//随机产生 n 个元素的值，建立带表头节点的单链线性表L（头插法）
void createListHead(LinkList *L, int n);
void createCirculateDoubleListTail(DLinkList L, int n);
void createDoubleList(DLinkList L, int n);
void createSymmetricDoubleList(DLinkList L, int n);
void createSymmetricLinkList(LinkList L, int n);
void createIncreaseListHead(LinkList *L, int n);

//随机产生 n 个元素的值，建立带表头节点的单链线性表L（尾插法）
void createListTail(LinkList *L, int n);
void createCircleListTail(LinkList L, int n);

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
bool ListTraverse_DL(DLinkList L);

bool IsEmpty(LinkList L);

/**
 * 原地翻转链表
 * @param L 链表
 * @return LinkList
 */
LinkList ReverseList_L(LinkList L);
LinkList ReverseList(LinkList L);
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

/**
 * 删除有序链表中的重复元素 ,时间复杂度 O(n) 空间复杂度 O(1)
 *
 * @param L 递增有序链表
 */
void DeleteRepeatElement(LinkList L);

/**
 * 合并两个单调递增的有序序列
 * @param L1
 * @param L2
 */
void MergeList(LinkList L1, LinkList L2);

/**
 * 在递增的两个序列中把相同的节点组成一个新的链表并返回
 * @param L1 递增有序链表
 * @param L2 递增有序链表
 * @return L1,l2 中共同元素组成的链表
 */
LinkList FindSameElement(LinkList L1, LinkList L2);

/**
 * 求 L1与 L2的交集
 * @param L1 递增有序链表
 * @param L2 递增有序链表
 */
void UnionLinkList(LinkList L1, LinkList L2);

/**
 * 判断循环双链表是否对称
 * @param L 循环双链表
 * @return 对称 true
 */
bool symmetry(DLinkList L);

/**
 * 合并两个链表 L1，L2。L2并入到L1后
 * @param L1 循环双链表
 * @param L2 循环双链表
 */
void connectDLinkList(DLinkList L1, DLinkList L2);
void connectLindList(LinkList L1, LinkList L2);

/**
 * 循环删除单链表中的最小节点，直至链表为空
 * @param L1 循环单链表
 */
void deleteSmall(LinkList L1);

/**
 * 在带有表头节点的非循环双向链表中定位元素并返回节点，同时设置节点访问频率并按频率进行排序始终然频率大的在最前
 * @param L 带有表头节点的非循环双向链表
 * @param elem 定位元素
 * @return 节点==L -> 没有找到 else 找到
 */
DNode *Locate(DLinkList L, ElemType elem);


/**
 * 在单链表中找到倒数 k个元素同时打印出来
 * @param L 链表
 * @param K 倒数 k 个元素
 * @return if find return true else return false;
 */
bool findLastK(LinkList L, int K);

/**
 * 寻找两个单链表的共同后缀
 * @param L1 单链表
 * @param L2 单链表
 * @return 共同后缀节点
 */
LNode *findCoNode(LinkList L1, LinkList L2);

/**
 * 单链表长度
 * @param list 单链表
 * @return 长度
 */
int listLength(LinkList list);

/**
 * 删除单链表中绝对值重复的节点(值域为0...n)，只保留第一次出现的节点
 * @param list 单链表
 * @param n 值域上边界
 */
void deleteRepeat(LinkList list, int n);

/**
 * 找单链表的环入口
 * @param list
 * @return
 */
LNode *findLoopStart(LinkList list);

/**
 * 按值查找链表中的元素并返回节点
 * @param list
 * @param elem
 * @return
 */
LNode *findNode(LinkList list, ElemType elem);
LNode *findLastNode(LinkList list);

/**
 * 把链表对折后相间融合
 * @param list
 */
void changeList(LinkList list);

#endif//DATASTRUCTWITHC_LINKLIST_H
