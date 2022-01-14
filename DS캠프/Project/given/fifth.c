#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "omok.h"

int main(void){
    int omok=0;
    int count=0;
    int x, y;
    int user=1;

    void printOrigin();
    // 4세 이상 확인 !@#$%
    int ans, age;
    printf("4세 이상입니까? (0:N, 1:Y) : ");
    scanf("%d",&ans);
    if(ans==0) {
      printf("현재 나이를 입력하세요. > ");
      scanf("%d",&age);
      printf("%d년 후에 다시 오십시오.\n",4-age);
      return 0;
    }

    // 바둑판 만들기 -> 2차원 배열 (19*19) : 0으로 초기화 !@#$%
    int board[15][15] = {0, };

    //usleep(2000000);

    //좌표 검사 !@#$%
    while(count<=(19*19)){
        system("clear");
        drawMap(board);

        while(1){
          if(user==1) printf("흑돌 차례입니다.\n");
          else printf("백돌 차례입니다.\n");
          printf("바둑돌을 둘 좌표(x,y)를 입력하세요. > ");
          scanf("%d %d", &x, &y);
          if(x<0 || x>19 || y<0 || y>19) {
              printf("범위를 벗어나는 좌표 입니다.\n");
            }
          else if(board[y][x]!=0){
             printf("이미 바둑돌이 있는 좌표 입니다.\n");
            }else{
              break;
            }
        }

        // 배열에 좌표 추가
        addPoint(board, user, x, y);
        // list[point->x][point->y] = user

        // ** 바둑판 그리기
        // printf("-------------------")

        // ** 오목 검사 (종료 여부 결정)
        // printf("%d ", omok);
        omok = checkOmok(board);
        if(omok==1){
            break;        
        }

        // 유저 변경
        if(user==1){
            user=2;
        }else{
            user=1;
        }

        // 횟수 증가
        count++;
    }

    // 멘트 출력 !@#$%
    printf("게임 종료!\n");
    if(user==1) printf("흑돌 승!");
    else printf("백돌 승!");

    return 0;
}
