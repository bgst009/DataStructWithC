//
// Created by 14991 on 2020/8/22.
//

#ifndef DATASTRUCTWITHC_SQ_STACK_H
#define DATASTRUCTWITHC_SQ_STACK_H

#define MAXSIZE 15

#include "../header.h"

typedef int SElemType;
typedef struct {
    SElemType data[MAXSIZE];
    //栈顶元素下标
    int top;
} SqStack;

bool InitStack_Sq(SqStack *);

bool DestroyStack_Sq(SqStack *);

bool ClearStack_Sq(SqStack *);

bool StackEmpty_Sq(SqStack *);

bool GetTop_Sq(SqStack *, SElemType *);

bool Push_Sq(SqStack *, SElemType);

bool Pop_Sq(SqStack *, SElemType *);

int StackLength_Sq(SqStack *);

#endif //DATASTRUCTWITHC_SQ_STACK_H
