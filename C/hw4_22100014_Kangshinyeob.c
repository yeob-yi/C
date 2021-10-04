// 한 개의 정수 값(년도)을 입력받아 윤년인지 여부를 판단하는 프로그램
#include <stdio.h>

int main(void){
    int year;

    printf("연도를 입력하세요. ");
    scanf("%d", &year);

    if(year%100==0 && year%400!=0){
        printf("윤년이 아닙니다.");
    }else if(year%4==0){
        printf("윤년입니다.");
    }else{
        printf("윤년이 아닙니다.");
    }
    
    return 0;
}