#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "omok.h"

// 시작멘트 출력 (오목의 기원에 대하여 ,,)

void printOrigin(){
    system("clear");
    char originMent[21][1000] = {"\n", "\n", "About the origin of Gomoku", "Gomoku has existed in Japan since the Meiji Restoration (1868).", "The name 'gomoku' is from the Japanese language, in which it is referred to as gomokunarabe (五目並べ).", "Go means five, moku is a counter word for pieces and narabe means line-up.", "The game is popular in China, where it is called Wuziqi (五子棋).", "Wu (五 wǔ) means five, zi (子 zǐ) means piece, and qi (棋 qí) refers to a board game category in Chinese.", "The game is also popular in Korea, where it is called omok (오목 [五目]) which has the same structure and origin as the Japanese name.", "In the nineteenth century, the game was introduced to Britain where it was known as Go Bang, said to be a corruption of the Japanese word goban, which was itself adapted from the Chinese k'i pan (qí pán) 'go-board.'"};
    for(int i=0; i<20; i++){
        for(int j=i; j<20; j++){
            if(j%2==0){
                printf("%s\n", originMent[j/2]);
            }else{
                printf("\n");
            }
        }
        sleep(1);
        system("clear");
    }
}


// 배열에 점 추가
void addPoint(Stack* stack, int list[][15], int user, point p){
    list[p.y][p.x] = user;
    if(stack->len == 0){
        stack->array = (point*)malloc(sizeof(point));
    }else{
        stack->array = (point*)realloc(stack->array, sizeof(point)*(stack->len+1));
    }
}

int popPoint(Stack* stack, int list[][15]){
    if(stack->len == 0){
        return 0;
    }else{
        point result = stack->array[stack->len-1];
        stack->len--;
        list[result.y][result.x] = 0;

        return stack->len--;
    }
}
*/


// 바둑판 그리기
void drawMap(int list[][15]){
    system("clear");
    for(int y=-1; y<15; y++){
        for(int x=-1; x<15; x++){
            if(x==-1 && y==-1){
                printf("  ");
            }else if(x==-1){
                if(y==0 || y==4){
                    printf("%2d", y+1);                    
                }else if(y==9 || y==14){
                    printf("%2d", y+1);
                }else{
                    printf("  ");
                }
            }else if(y==-1){
                if(x==0 || x==4){
                    printf("%-2d", x+1);
                }else if(x==8 || x==13){
                    printf("%3d", x+2);
                }else{
                    printf("  ");
                }
            }else{
                if(list[y][x]==1){
                    printf("○");
                }else if(list[y][x]==2){
                    printf("●");
                }else{
                    if(x==0 && y==0){
                        printf("┌");
                    }else if(x==14 && y==0){
                        printf("┐");
                    }else if(y==14 && x==0){
                        printf("└");
                    }else if(x==14 && y==14){
                        printf("┘");
                    }else if(x==0){
                        printf("├");
                    }else if(y==0){
                        printf("┬");
                    }else if(x==14){
                        printf("┤");
                    }else if(y==14){
                        printf("┴");
                    }else{
                        printf("┼");
                    }
                    
                }
            }
            if(x==14){
                printf("\n");
            }else if(x!=(-1) && y!=(-1)){
                printf("─");
            }

        }
    }
    printf("\n");
}

// 오목인지 확인
int checkOmok(int list[][15]){
    int temp;
    // 1. 가로, 세로로 5개가 연결되었는가
    for(int y=0; y<15; y++){
        for(int x=0; x<11; x++){
            temp = list[y][x];
            if(temp!=0 && temp==list[y][x+1] && temp==list[y][x+2] && temp==list[y][x+3] && temp==list[y][x+4]){
                return 1;
            }
            if(temp!=0 && temp==list[y+1][x] && temp==list[y+2][x] && temp==list[y+3][x] && temp==list[y+4][x]){
                return 1;
            }
        }
    }
    // 2. 세로로 5개가 연결되었는가

    // 3. 대각선 1번으로 5개가 연결되었는가
    for(int y=0; y<11; y++){
        for(int x=0; x<11; x++){
            temp = list[y][x];
            if(temp!=0 && temp==list[y+1][x+1] && temp==list[y+2][x+2] && temp==list[y+3][x+3] && temp==list[y+4][x+4])
                return 1;
        }
    }
    // 4. 대각선 2번으로 5개가 연결되었는가
    for(int y=0; y<11; y++){
        for(int x=4; x<15; x++){
            temp = list[y][x];
            if(temp !=0 && temp==list[y+1][x-1] && temp==list[y+2][x-2] && temp ==list[y+3][x-3] && temp==list[y+4][x-4])
                return 1;
            }
        }

    return 0;
}

void printCredit(){
    system("clear");
    char creditMent[10][100] = {"\n", "\n", "          CRA 2021 DS 캠프", "     1조: 오목게임 만들기 프로젝트", "\n", "              만든사람", "         ○ 22100014 강신엽", "         ● 22100220 김하람"};
    for(int i=0; i<16; i++){
        for(int j=i; j<16; j++){
            if(j%2==0){
                printf("%s\n", creditMent[j/2]);
            }else{
                printf("\n");
            }
        }
        sleep(1);
        system("clear");
    }
}