// 어떤 주어진 일자의 다음 날을 구하는 프로그램
#include <stdio.h>

int main(void){
    int year, month, date;
    int leapYear = 0;
    int monthdate[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("날짜를 입력하세요.(연 월 일) ");
    scanf("%d %d %d", &year, &month, &date);

    if(year%100==0 && year%400!=0){
        leapYear=0;
    }else if(year%4==0){
        leapYear=1;
    }else{
        leapYear=0;
    }

    if(monthdate[month-1]==date){
        if(month==12){
            printf("입력한 날짜의 다음 날은 %d년 %d월 %d일입니다.", year+1, 1, 1);
        }else if(leapYear==1 && month==2){
            printf("입력한 날짜의 다음 날은 %d년 %d월 %d일입니다.", year, month, 29);
        }else{
            printf("입력한 날짜의 다음 날은 %d년 %d월 %d일입니다.", year,month+1,1);
        }
    }else{
        printf("입력한 날짜의 다음 날은 %d년 %d월 %d일입니다.", year, month, date+1);
    }


    return 0;
}