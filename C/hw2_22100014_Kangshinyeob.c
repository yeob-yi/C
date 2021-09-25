// 세 개의 정수를 입력받아 최댓값 최솟값 및 평균값 구하는 프로그램
#include <stdio.h>

int main(void){
    int num1, num2, num3;
    int max, min;
    float average;

    printf("세 개의 정수를 입력하세요 ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    max = num1;
    if(max<num2){
        max = num2;
    }
    if(max<num3){
        max = num3;
    }

    min = num1;
    if(min>num2){
        min = num2;
    }
    if(min>num3){
        min = num3;
    }

    average = (num1 + num2 + num3)/3;
    
    printf("최댓값은 %d, 최솟값은 %d, 평균은 %.1f입니다.", max, min, average);

    return 0;
}