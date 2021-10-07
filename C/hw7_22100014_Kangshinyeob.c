// 1~n(n>1) 범위의 정수 중에서 완전수 찾기
#include <stdio.h>

int main(void){
    int n;
    int y=0;
    int sum;

    printf("2 이상의 정수 입력: ");
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        sum=0;
        for(int j=1; j<i; j++){
            if(i%j==0){
                sum+=j;
            }
        }
        if(i==sum){
            printf("%d ", i);
            y=1;
        }
    }

    if(y==1)
        printf("은(는) 완전수 입니다.");
    else
        printf("1부터 %d 범위의 정수 중에는 완전수가 없습니다.", n);
        
    return 0;
}