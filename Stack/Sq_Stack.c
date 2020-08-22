//
// Created by 14991 on 2020/8/22.
//

#include "Sq_Stack.h"

bool InitStack_Sq(SqStack *sqStack) {
    //栈空
    sqStack->top = -1;
}

bool DestroyStack_Sq(SqStack *sqStack) {
    if (sqStack) {
        free(sqStack);
        return true;
    } else {
        printf("\n The Stack is Not exist \n");
        return false;
    }
}

//初始条件：栈存在
//操作结果：清空栈
bool ClearStack_Sq(SqStack *sqStack) {
    if (sqStack) {
        sqStack->top = -1;
        return true;
    } else {
        printf("\n The Stack is Not exist \n");
        return false;
    }
}

bool StackEmpty_Sq(SqStack *sqStack) {
    if (sqStack) {
        sqStack->top = -1;
        return true;
    } else {
        printf("\n The Stack is Not exist \n");
        return false;
    }
}

bool GetTop_Sq(SqStack *sqStack, SElemType *elem) {
    if (sqStack) {
        *elem = sqStack->data[sqStack->top];
        return true;
    } else {
        printf("\n The Stack is Not exist \n");
        return false;
    }
}

bool Push_Sq(SqStack *sqStack, SElemType elem) {
    if (sqStack) {
        if (sqStack->top >= MAXSIZE - 1) {
            printf("\n Stack is Full!!! \n");
            return false;
        } else {
            sqStack->top += 1;
            sqStack->data[sqStack->top] = elem;
            return true;
        }
    } else {
        printf("\n The Stack is Not exist \n");
        return false;
    }
}

bool Pop_Sq(SqStack *sqStack, SElemType *elem) {
    if (sqStack) {
        if (sqStack->top <= -1) {
            printf("\n Stack is empty!!! \n");
            return false;
        } else {
            *elem = sqStack->data[sqStack->top];
            sqStack->top -= 1;
            return true;
        }
    } else {
        printf("\n The Stack is Not exist \n");
        return false;
    }
}

int StackLength_Sq(SqStack *sqStack) {
    if (sqStack) {
        return sqStack->top + 1;
    } else {
        printf("\n The Stack is Not exist \n");
        return 0;
    }
}