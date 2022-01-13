#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"


int main(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->len = 0;

    int count=0;
    char cmd[10];
    int value;

    scanf("%d", &count);
    for(int i=0; i<count; i++){
        scanf("%s", cmd);
        if(strncmp(cmd, "push", 4)==0){
            scanf("%d", &value);
            push(stack, value);
        }else if(strncmp(cmd, "pop", 3)==0){
            value = pop(stack);
            printf("%d", value);
        }else if(strncmp(cmd, "size", 4)==0){
            printf("%d", stack->len);
        }else if(strncmp(cmd, "empty", 5)==0){
            if(stack->len==0){
                value = 1;
            }else{
                value = 0;
            }
            printf("%d", value);
        }else if(strncmp(cmd, "top", 3)==0){
            value=pop(stack);
            printf("%d", value);
            if(value!=-1)
                push(stack, value);
        }
    }

    free(stack);

    return 0;
}