//
// Created by bgst on 2020/9/11.
//

#ifndef DATASTRUCTWITHC_DYNAMICSTACK_H
#define DATASTRUCTWITHC_DYNAMICSTACK_H
#include "./Array.h"

typedef Array Stack;
typedef ArrayElementType StackElementType;
Stack cstl_stack_initStack(int capacity);
int cstl_stack_getLength(Stack stack);
bool cstl_stack_isEmpty(Stack stack);
int cstl_stack_capacity(Stack stack);
void cstl_stack_push(Stack* stack, StackElementType element);
StackElementType cstl_stack_pop(Stack* stack);
StackElementType cstl_stack_top(Stack stack);
void cstl_stack_print(Stack stack);
#endif//DATASTRUCTWITHC_DYNAMICSTACK_H
