//
// Created by 14991 on 2020/8/16.
//

#ifndef DATASTRUCTWITHC_SQLIST_H
#define DATASTRUCTWITHC_SQLIST_H


#include "../../header.h"

#define ListInitSize  100
#define ListIncrement  10
#define MAXSIZE 15
typedef int ElemType;

/* ================================     SqList ============================ */

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

/**
 * 初始化线性表
 * @param L 线性表
 * @return
 */
bool InitList_Sq(SqListDynamic *L);
//DestroyList
bool DestroyList_Sq(SqListDynamic *L);
//ClearList
bool ClearList_Sq(SqListDynamic *L);
//ListEmpty
bool ListEmpty_Sq(SqListDynamic L);
//GetElem
bool GetElem_Sq(SqListDynamic L, int i, ElemType *e);

//ListLength
int ListLength_Sq(SqListDynamic L);
//ListTraverse
bool ListTraverse_Sq(SqListDynamic L);
//LocateElem
bool LocateElem_Sq(SqListDynamic L, ElemType e, int *index);
//PriorElem
bool PriorElem_Sq(SqListDynamic L, ElemType cur_e, ElemType *pre_e);
//NextElem
bool NextElem_Sq(SqListDynamic L, ElemType cur_e, ElemType *next_e);
//ListInsert
bool ListInsert_Sq(SqListDynamic *L, int i, ElemType e);
//ListDelete
bool ListDelete_Sq(SqListDynamic *L, int i, ElemType *e);







#endif //DATASTRUCTWITHC_SQLIST_H
