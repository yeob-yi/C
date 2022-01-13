#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(Stack* stack, int num){
    if(stack->len == 0){
        stack->array = (int*)malloc(sizeof(int));
    }else{
        stack->array = (int*)realloc(stack->array, sizeof(int)*(stack->len+1));
    }
    
    stack->array[stack->len] = num;
    stack->len++;
}

int pop(Stack* stack){
    if(stack->len == 0){
        return -1;
    }else{
        int result = stack->array[stack->len-1];
        stack->len--;

        return result;
    }
}