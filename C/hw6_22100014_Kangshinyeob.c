// 주어진 두 개의 정수(n1, n2)에 대한 최대 공약수를 구하는 프로그램
#include <stdio.h>

int main(void){
    int n1, n2;
    int i;

    printf("두 개의 정수(n1, n2)를 입력하세요. ");
    scanf("%d %d", &n1, &n2);
    
    if(n1<1 || n2<1){
        printf("음수를 입력하였습니다.");
    }else{
        if(n1>n2){
            i=n2;
        }else{
            i=n1;
        }
        while(i>0){
            if(n1%i==0 && n2%i==0){
                printf("최대 공약수는 %d입니다.", i);
                break;
            }
            i--;
        }
    }

    return 0;
}