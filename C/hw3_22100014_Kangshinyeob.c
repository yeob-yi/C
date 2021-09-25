// 각 평가 요소의 점수를 입력 받아, 최종 학점을 출력하는 프로그램
#include <stdio.h>

int main(void){
    // 1. 변수 선언 : 중간고사 점수, 기말고사 점수, 과제 점수, 학점
    int score1, score2, score3;
    float score;

    // 2. 중간고사 점수, 기말고사 점수, 과제 점수 입력받기
    printf("중간고사 점수 입력: ");
    scanf("%d", &score1);
    printf("기말고사 점수 입력: ");
    scanf("%d", &score2);
    printf("과제 점수 입력: ");
    scanf("%d", &score3);

    // 3. 가중치 계산 : 중간(35%), 기말(45%), 과제(20%)
    score = score1*0.35 + score2*0.45 + score3*0.2;

    // 4. 학점 출력
    if(score<60){
        printf("최종 학점은 F입니다.");
    }else if(60<=score && score<70){
        printf("최종 학점은 D입니다.");
    }else if(70<=score && score<80){
        printf("최종 학점은 C입니다.");
    }else if(80<=score && score<90){
        printf("최종 학점은 B입니다.");
    }else{
        printf("최종 학점은 A입니다.");
    }

    return 0;
}