// 임의의 날짜에 대하여 요일을 알아내는 프로그램 (1900년 1월 1일 이후만 고려)
#include <stdio.h>

int isYun(int y){
    if(y%400==0)
        return 0;
    else if(y%100==0)
        return 1;
    else if(y%4==0) 
        return 0;
    else
        return 1;
    return 0;
}
int main(void){
    int year, month, date;
    int y=1900, m=0;
    int yun=0;
    int total=0;
    int monthdate[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char day[7][100]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int dayday;
    int aa;
    

    // 1. 연, 월, 일 입력받기
    printf("입력 : ");
    scanf("%d %d %d", &year, &month, &date);

    // 2. 1900년 1월 1일부터 입력받은 날짜까지 총 몇일인지 계산 ( ((연-1)-1900)*365 + (1900년부터 입력받은 연도까지 윤년 수) + 월*일 + 일 )
    //     2-1. ((연도-1)-1900)*365
    total = ((year-1)-1900)*365;
    //     2-2. 1900년부터 입력받은 연도까지 윤년 수 계산 
    //         2-2-1. 윤년 체크해서 더하기 (400으로 나누어지면 윤년 / 100으로 나누어지면 윤년 아님 / 4로 나누어지면 윤년)
    while(y<year){
        aa=isYun(y);
        if(aa==0) 
            total++;
        y++;
    }
    //     2-3. 월*일 더하기
    while(m<month-1){
        total+=monthdate[m];
        aa=isYun(year);
        if(aa==0 && m==2)
            total++;
        m++;
    }
    //     2-4. 일 더하기
    total+=date;
    
    // 3. 2 결과 % 7 해서 나머지에 따라 요일 출력
    dayday=total%7;

    //     3-1. 오늘 날짜 넣어서 맞춰보기
    printf("%s", day[dayday]);

    return 0;
}

