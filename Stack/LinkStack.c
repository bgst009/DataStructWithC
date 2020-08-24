//
// Created by bgst on 2020/8/24.
//

#include "LinkStack.h"


bool InitStack_LS(LinkStack *linkStack) {
    linkStack->count = 0;
}

bool DestroyStack_LS(LinkStack *linkStack) {

}

bool ClearStack_LS(LinkStack *linkStack) {

}

bool StackEmpty_LS(LinkStack linkStack) {
    return (linkStack.count == 0) ? true : false;
}

bool Push_LS(LinkStack *linkStack, SElemType elem) {
    LinkStackPtr node = (LinkStackPtr) malloc(sizeof(LinkStack));
    node->data = elem;
    node->next = linkStack->top;
    linkStack->top = node;
    linkStack->count++;
    return true;
}

bool Pop_LS(LinkStack *linkStack, SElemType *elem) {
    if (StackEmpty_LS(*linkStack))
        return false;
    LinkStackPtr node = linkStack->top;
    linkStack->top->next = node->next;
    *elem = node->data;
}

bool Top_LS(LinkStack *linkStack, SElemType *elem);

int StackLength_LS(LinkStack linkStack);
