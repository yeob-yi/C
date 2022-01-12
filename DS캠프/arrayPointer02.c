#include <stdio.h>

int main(void){
    // 1. 크기가 5인 int형 배열 선언 후 {1, 2, 3, 4, 5}로 초기화
    int arr[5] = {1, 2, 3, 4, 5};
    int times = sizeof(arr)/sizeof(int);

    // 2. 배열 이름으로 모든 배열의 값 [주소: 값] 형태로 출력
    for(int i=0; i<times; i++){
        printf("%p:%d\n", (arr+i), *(arr+i));
    }

    // 3. 배열 이름을 사용해 배열의 모든 요소 값 2 증가
    for(int i=0; i<times; i++){
        *(arr+i) +=2;
    }

    // 4. 배열 이름으로 전체 배열
    printf("\n");
    for(int i=0; i<times; i++){
        printf("%p:%d\n", (arr+i), *(arr+i));
    }
}