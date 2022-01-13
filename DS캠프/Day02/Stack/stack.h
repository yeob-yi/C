#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack {
    int* array;
    int len;
} Stack;

void push(Stack* stack, int num);
int pop(Stack* stack);

#endif