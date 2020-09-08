//
// Created by bgst on 2020/9/7.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdbool.h>

#include "../list/LinkList.h"

/**
 * 动态分配内存的顺序栈
 */

typedef int StackElement;
typedef struct MyStack {
    StackElement* data;
    int top;
    int size;
} Stack;


Stack init(int size);
bool destroy(Stack* stack);
bool push(Stack* stack, StackElement element);
bool pop(Stack* stack);
StackElement top(Stack* stack);
bool isEmpty(Stack* stack);
bool symmetryWithStack(LinkList L, Stack* stack);
void traverseStack(Stack* stack);

#endif//STACK_STACK_H
