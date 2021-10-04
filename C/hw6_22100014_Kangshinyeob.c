// 주어진 두 개의 정수(n1, n2)에 대한 최대 공약수를 구하는 프로그램
#include <stdio.h>

int main(void){
    int n1, n2;
    int i;
    int no=0;

    printf("두 개의 정수(n1, n2)를 입력하세요. ");
    scanf("%d %d", &n1, &n2);

    if(n1>n2){
        i=n2;
    }else{
        i=n1;
    }
    
    while(i>0){
        if(n1%i==0 && n2%i==0){
            no=1;
            printf("최대 공약수는 %d입니다.", i);
            break;
        }
        i--;
    }
    if(no==0){
        printf("공약수가 존재하지 않습니다.");
    }

    return 0;
}