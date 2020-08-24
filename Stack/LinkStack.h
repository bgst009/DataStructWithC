//
// Created by bgst on 2020/8/24.
//

#ifndef DATASTRUCTWITHC_LINKSTACK_H
#define DATASTRUCTWITHC_LINKSTACK_H

#include "../header.h"

typedef int SElemType;

typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;

bool InitStack_LS(LinkStack *);

bool DestroyStack_LS(LinkStack *);

bool ClearStack_LS(LinkStack *);

bool StackEmpty_LS(LinkStack linkStack);

bool Push_LS(LinkStack *linkStack, SElemType elem);

bool Pop_LS(LinkStack *linkStack, SElemType *elem);

bool Top_LS(LinkStack *linkStack, SElemType *elem);

int StackLength_LS(LinkStack linkStack);

#endif //DATASTRUCTWITHC_LINKSTACK_H
