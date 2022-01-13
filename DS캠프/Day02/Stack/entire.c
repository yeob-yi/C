#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack {
    int* array;
    int len;
} Stack;

void push(Stack* stack, int num);
int pop(Stack* stack);


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
            printf("%d\n", value);
        }else if(strncmp(cmd, "size", 4)==0){
            printf("%d\n", stack->len);
        }else if(strncmp(cmd, "empty", 5)==0){
            if(stack->len==0){
                value = 1;
            }else{
                value = 0;
            }
            printf("%d\n", value);
        }else if(strncmp(cmd, "top", 3)==0){
            value=pop(stack);
            printf("%d\n", value);
            if(value!=-1)
                push(stack, value);
        }
    }

    free(stack);

    return 0;
}

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