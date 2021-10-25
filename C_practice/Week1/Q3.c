#include <stdio.h>
// 1-3. 섭씨 온도를 화씨 온도로 변환

int main(void){
    float c_degree=0;
    float f_degree=0;

    // 1. 섭씨 온도 입력받기
    printf("섭씨 온도를 입력하시오. ");
    scanf("%f", &c_degree);

    // 2. 화씨 온도로 변환 ( 화씨 온도 = 섭씨 온도 * 1.8 + 3.2)
    f_degree = c_degree*1.8 + 32;

    // 3. 출력
    printf("화씨 온도는 %.1f 도 입니다.", f_degree);

    return 0;
}