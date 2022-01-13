#include <stdio.h>

int main(void){
    int arr[5] = {1, 2, 3, 4, 5};
    int* p = &arr[0];
    int times = sizeof(arr)/sizeof(int);
    
    for(int i=0; i<times; i++){
        *(p+i) +=2;
    }
    for(int i=times-1; i>=0; i--){
        printf("%d\n", *(p+i));
    }
}