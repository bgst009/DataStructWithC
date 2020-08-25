//
// Created by bgst on 2020/8/24.
//

#include "LinkStack.h"


bool InitStack_LS(LinkStack *linkStack) {
    linkStack->stack_size = 0;
    StackNode *top = (LinkStackPtr) malloc(sizeof(StackNode));
    if (!top)
        return true;
    top->next = NULL;
    top->data = 0;
    linkStack->top = top;

    return true;
}

bool DestroyStack_LS(LinkStack *linkStack) {
    StackNode *tmp_mode;
    while (linkStack->top->next) {
        tmp_mode = linkStack->top->next;
        linkStack->top->next = tmp_mode->next;
        free(tmp_mode);
    }
    //栈空
    linkStack->stack_size = 0;
    //删除头节点
    free(linkStack->top);
    //删除链表
    linkStack = NULL;
    return true;

}

bool ClearStack_LS(LinkStack *linkStack) {
    StackNode *tmp_mode;
    while (linkStack->top->next) {
        tmp_mode = linkStack->top->next;
        linkStack->top->next = tmp_mode->next;
        free(tmp_mode);
    }
    //栈空
    linkStack->stack_size = 0;
    return true;
}

bool StackEmpty_LS(LinkStack *linkStack) {
    return (linkStack->stack_size <= 0) ? true : false;
}

bool Push_LS(LinkStack *linkStack, SElemType elem) {
    //带头结点的单链表的头插
    StackNode *new_node = (LinkStackPtr) malloc(sizeof(StackNode));
    //节点申请失败
    if (!new_node) {
        printf("\n fail to malloc new space of node \n");
        return false;
    }
    //申请节点成功
    new_node->data = elem;
    new_node->next = linkStack->top->next;
    linkStack->top->next = new_node;
    linkStack->stack_size++;
    return true;
}

bool Pop_LS(LinkStack *linkStack, SElemType *elem) {
    //带头结点单链表在队头删除节点
    if (StackEmpty_LS(linkStack)) {
        printf("\n Stack is empty \n");
        return false;
    }
    StackNode *new_node = (LinkStackPtr) malloc(sizeof(StackNode));
    //节点申请失败
    if (!new_node) {
        printf("\n fail to malloc new space of node \n");
        return false;
    }
    //申请节点成功
    new_node = linkStack->top->next;
    *elem = new_node->data;
    linkStack->top->next = new_node->next;
    free(new_node);
    new_node = NULL;
    linkStack->stack_size--;
    return true;;
}

bool Top_LS(LinkStack *linkStack, SElemType *elem) {
    if (StackEmpty_LS(linkStack)) {
        printf("\n Stack is empty \n");
        return false;
    }

    *elem = linkStack->top->next->data;
    return true;;
}

int StackLength_LS(LinkStack *linkStack) {
    return linkStack->stack_size;
}

bool print_LS(LinkStack *linkStack) {
    if (linkStack == NULL) {
        printf("\n Stack not exist!! \n");
        return false;
    }

    if (StackEmpty_LS(linkStack)) {
        printf("\n Stack is Empty!! \n");
        return false;
    }
    SElemType elem;

    while (linkStack->stack_size) {
        Pop_LS(linkStack, &elem);
        printf(" %d ", elem);
    }

    return true;
}