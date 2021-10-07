// 1~n(n>1) 범위의 정수 중에서 완전수 찾기
#include <stdio.h>

int main(void){
    int n; 
    int sum=0;

    printf("정수 입력: ");
    scanf("%d", &n);

    for(int i=1; i<n; i++){
        if(n%i==0){
            sum+=i;
        }        
    }

    if(sum==n){
        printf("완전수입니다.");
    }else{
        printf("완전수가 아닙니다.");
    }
    return 0;
}