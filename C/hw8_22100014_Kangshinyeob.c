// 구구단 출력 프로그램
#include <stdio.h>

int main(void){
    int n;

    printf("Select a column of multiplication table : ");
    scanf("%d", &n);

    for(int i=1;i<=9;i++){
        printf("%d * %d = %d\n", n, i, n*i);
    }

    return 0;
}