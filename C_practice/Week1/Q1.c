#include <stdio.h>

int main(void) {
  // 1. 태어난 년도 입력받기
  // 2. 입력받은 년도 이용해 나이 계산하기
  // 3. 계산한 나이 출력하기

  int birth_year; // 태어난 년도 
  int age; // 나이 

  printf("Birth year? ");
  scanf("%d", &birth_year);
  age = 2021-birth_year+1;
  printf("%d", age);

  return 0;
}