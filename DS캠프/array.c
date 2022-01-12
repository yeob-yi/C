#include <stdio.h>

int main(void){
    int arr[3] = {1, 2, 3};

    printf("%p\n", arr);
    printf("%p", &arr[0]);

    return 0;
}