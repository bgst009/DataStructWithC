//
// Created by bgst on 2020/9/7.
//

#ifndef STACK_DUALSTACK_H
#define STACK_DUALSTACK_H
#include <stdbool.h>
//#define MAXSIZE 20
typedef struct DualStack {
    int* data;
    int top[2];
    int size;
} DStack;
typedef int StackElement;

DStack initD(int size);
bool destroyD(DStack* stack);
bool pushD(DStack* stack, StackElement element, int i);
bool popD(DStack* stack, int i);
StackElement topD(DStack* stack, int i);
bool isEmptyD(DStack* stack, int i);
void traverseStackD(DStack stack);


#endif//STACK_DUALSTACK_H
