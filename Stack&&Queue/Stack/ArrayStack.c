//
// Created by bgst on 2020/9/10.
//

#include "ArrayStack.h"

#include <assert.h>
#include <stdio.h>
struct Array {
    ArrayElementType* data;
    //数组容量
    int capacity;
    //元素个数
    int length;
};

Stack cstl_stack_initStack(int capacity) {
    return cstl_array_initArray(capacity);
}
int cstl_stack_getLength(Stack stack) {
    return cstl_array_getLength(stack);
}
bool cstl_stack_isEmpty(Stack stack) {
    return cstl_array_isEmpty(stack);
}
int cstl_stack_capacity(Stack stack) {
    return cstl_array_getCapacity(stack);
}
void cstl_stack_push(Stack* stack, StackElementType element) {
    cstl_array_addLast(stack, element);
}
StackElementType cstl_stack_pop(Stack* stack) {
    if (cstl_stack_isEmpty(*stack)) {
        printf("\n stack is empty ");
    }
    return cstl_array_removeLast(stack);
}
StackElementType cstl_stack_top(Stack stack) {
    return cstl_array_getLast(stack);
}
void cstl_stack_print(Stack stack) {
    printf("\n");

    while (!cstl_stack_isEmpty(stack)) {
        printf(" %d ", cstl_stack_pop(&stack));
    }
    printf("\n");
}

int main() {
    Stack stack = cstl_stack_initStack(5);
    printf("%d\n", cstl_stack_getLength(stack));
    printf("%d\n", cstl_stack_capacity(stack));
    for (int i = 0; i < 5; i++) {
        cstl_stack_push(&stack, i);
    }
    cstl_stack_print(stack);
    printf("%d\n", cstl_stack_getLength(stack));
    printf("%d\n", cstl_stack_capacity(stack));

    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", cstl_stack_pop(&stack));
    }
    return 0;
}
