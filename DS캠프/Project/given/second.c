#include <stdio.h>
#include <stdlib.h>
#include "omok.h"

int main(void){
  int omok=0;
  int count=0;
  int x, y;
  int user=1;
  //point p;
    void printOrigin();



    //--------------------------------
    // 4세 이상 확인 !@#$%
    int ans;
    int age;
    printf("4세 이상입니까? (0:N, 1:Y) : ");
    scanf("%d",&ans);
    if(ans==0) {
      printf("현재 나이를 입력하세요. > ");
      scanf("%d",&age);
      printf("%d년 후에 다시 오십시오.\n",4-age);
      return 0;
    }
    //------------------------------




    // 바둑판 만들기 -> 2차원 배열 (19*19) : 0으로 초기화 !@#$%
    int board[15][15] = {0, };

    //좌표 검사 !@#$%
    while(count<(19*19)){
      while(1){
        printf("바둑돌을 둘 좌표(x,y)를 입력하세요. > ");
        scanf("%d %d", &x, &y);
        if((x<0 || x>19) || (y<0 || y>19)) {
          printf("범위를 벗어나는 좌표 입니다.\n");
        }
        else {
          if(board[y][x]==0) {
            board[y][x]=1;
            break;
          }
          else printf("이미 바둑돌이 있는 좌표 입니다.\n");
            }
        }

        // 배열에 좌표 추가
        void addPoint(list, user, x, y);
            // list[point->x][point->y] = user

        // ** 바둑판 그리기
        void drawMap(list);
            // printf("-------------------")


        // ** 오목 검사 (종료 여부 결정)
        omok = int checkOmok(list);
        /*
            // 1. 가로로 5개가 연결되었는가
            for(int i=0; i<19; i++){
                for(int j=0; j<15; j++){
                    if(list[i][j]==list[i][j+1]==list[i][j+2]==list[i][j+3]==list[i][j+4])
                }
            }
            // 2. 세로로 5개가 연결되었는가
            for(int i=0; i<19; i++){
                for(int j=0; j<15; j++){
                    if(list[j][i]==list[j+1][i]==list[j+2][i]==list[j+3][i]==list[j+4][i])
                }
            }
            // 3. 대각선 1번으로 5개가 연결되었는가
            for(int i=0; i<15; i++){
                for(int j=0; j<15; j++){
                    if(list[i][j]==list[i+1][j+1]==list[i+2][j+2]==list[i+3][j+3]==list[i+4][j+4])
                }
            }
            // 4. 대각선 2번으로 5개가 연결되었는가
            for(int i=0; i<15; i++){
                for(int j=0; j<15; j++){
                    if(list[i][j]==list[i+1][j-1]==list[i+2][j-2]==list[i+3][j-3]==list[i+4][j-4])
                }
            }
        */
        if(omok==1)
            break;

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
    printf("게임 종료!");

    return 0;
}
