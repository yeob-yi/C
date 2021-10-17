// 어떤 월의 요일과 날짜수를 입력받아 달력을 출력하는 프로그램
#include <stdio.h>

int main(void){
    int yoil;
    int date;
    printf("1일의 요일 : ( 0: Sun,  1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat) : ");
    scanf("%d", &yoil);
    printf("Number of days : ");
    scanf("%d", &date);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for(int i=0; i<yoil; i++)
        printf("    ");
    for(int i=1; i<=date; i++, yoil++){
        printf("%3d ", i);
        if(yoil%7==6)
            printf("\n");
    }
    return 0;
}