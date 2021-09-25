// 섭씨 온도를 화씨 온도로 변환

#include <stdio.h>

int main(void){
    float celsius, fahrenheit;
    printf("섭씨 온도의 값: ");
    scanf("%f", &celsius);

    fahrenheit = celsius*1.8 + 32;
    printf("변환 값은 %.1f입니다.", fahrenheit);
    
    return 0;
}