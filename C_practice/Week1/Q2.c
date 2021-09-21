#include <stdio.h>

int main(void) {
  // 1. 신장(int, cm단위), 체중(int, kg단위), 비만도(float) 선언
  // 2. 신장 입력받기
  // 3. 체중 입력받기
  // 4. 비만도 계산하기(신장 단위 cm->m 변환해서)
  // 5. 비만도 출력하기

  int height, weight; // 신장(cm), 체중(kg) 
  float bmi; // 비만도 수치 

  printf("height? ");
  scanf("%d", &height);
  printf("weight? ");
  scanf("%d", &weight);
  bmi = weight/((height/100.0)*(height/100.0));
  printf("Your bmi is %.1f\n", bmi);
  return 0;
}