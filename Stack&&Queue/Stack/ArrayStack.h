//
// Created by bgst on 2020/9/10.
//

#ifndef DATASTRUCTWITHC_ARRAYSTACK_H
#define DATASTRUCTWITHC_ARRAYSTACK_H
#include <stdbool.h>

#include "../DynamicArray/Array.h"

typedef Array Stack;
typedef int StackElementType;

Stack cstl_stack_initStack(int capacity);
int cstl_stack_getLength(Stack stack);
bool cstl_stack_isEmpty(Stack stack);
int cstl_stack_capacity(Stack stack);
void cstl_stack_push(Stack* stack, StackElementType element);
StackElementType cstl_stack_pop(Stack* stack);
StackElementType cstl_stack_top(Stack stack);
void cstl_stack_print(Stack stack);


#endif//DATASTRUCTWITHC_ARRAYSTACK_H
