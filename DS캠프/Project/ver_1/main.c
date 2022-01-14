#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "omok.h"

int main(void){
    int omok=0;
    int count=0;
    int x, y;
    int user=1;
    int out, already;
    char dolName[5][10] = {"흑돌", "백돌"};

    printOrigin();

    // 4세 이상 확인
    int age;
    age = askAge();
    if(age == 0){
        exit(0);
    }

    // 바둑판 만들기 -> 2차원 배열 (19*19) : 0으로 초기화 !@#$%
    int board[15][15] = {0, };
    sleep(1);

    //좌표 검사 !@#$%
    while(count<=(19*19)){
        out = 0;
        already = 0;
        while(1){
            drawMap(board);
            if(out == 1){
              printf("범위를 벗어나는 좌표 입니다.\n\n");
            }
            if(already == 1){
              printf("이미 바둑돌이 있는 좌표 입니다.\n\n");
            }
            printf("%s 차례입니다.\n", dolName[user-1]);
            printf("바둑돌을 놓을 좌표(x,y)를 입력하세요. > ");
            scanf("%d %d", &x, &y);
            x = x-1;
            y = y-1;
            if((x<0) || (x>19) || (y<0) || (y>19)) {
                out = 1;
            }else if(board[y][x]!=0){
                already=1;
            }else{
                break;
            }
        }

        // 배열에 좌표 추가
        addPoint(board, user, x, y);
        
        // ** 오목 검사 (종료 여부 결정)
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


    // 게임 종료
    for(int i=8; i>0; i--){
        drawMap(board);
        printf("게임 종료!\n");
        if(i>5){
            printf("%d 수 만에 %s 승!\n", count+1, dolName[user-1]);        
        }else{
            printf("%d 수 만에 %s 승!   . . . . %d 초 후에 종료됩니다\n", count+1, dolName[user-1], i);
        }
        sleep(1);
    }

    printCredit();

    return 0;
}
