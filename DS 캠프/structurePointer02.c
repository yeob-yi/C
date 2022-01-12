// 직사각형 양 대각점 좌표 입력받아 넓이 구하는 프로그램
#include <stdio.h>

typedef struct Point {
    int x;
    int y;
} point;

typedef struct rectangle {
    point bottomLeft;
    point topRight;
} rect;

int size(rect r1);

int main(void){
    // 1. 점을 저장하는 구조체를 만들어 양 대각점 저장
    point p1, p2;
    rect rec1;

    printf("좌측 하단 점 입력 (x y) > ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("우측 상단 점 입력 (x y) > ");
    scanf("%d %d", &p2.x, &p2.y);

    // 2. 두 점을 저장하는 직사각형 구조체 제작
    rec1.bottomLeft = p1;
    rec1.topRight = p2;

    // 3. 매개변수로 직사각형이 주어지면 해당 직사각형의 넓이를 출력하는 함수 제작
    printf("넓이  : %d", size(rec1));

    return 0;
}

int size(rect r1){
    int width, height;
    int result;

    width = r1.topRight.x - r1.bottomLeft.x;
    height = r1.topRight.y - r1.bottomLeft.y;
    result = width*height;

    return result;
}