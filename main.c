#include <stdio.h>
#include <stdlib.h>

int main(){
    int answer[4][8] = {0};
    int sum[4] = {0};
    int temp;
    int count = 0;
    char mbti[4];
    char mbtioption[4][2] = {{'E', 'I'}, {'S', 'N'}, {'T', 'F'}, {'J', 'P'}};
    
    // 1. 32번 (0~5) 입력받기
    while(count<32){
        printf("[%02d/32] 0~5 사이 숫자 입력 >> ", count+1);
        scanf("%d", &temp);
        if(temp>=0 && temp<=5){
            answer[count%4][count/4] = temp;
            count++;
        }else{
            printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
        }
    }

    // 2. 4set 점수 계산
    for(int i=0; i<8; i++){
        for(int j=0; j<4; j++){
            sum[j] += answer[j][i];
            // sum[j] += answer[i*4+j];
        }
    }

    // 3. 16개 중 1개 표시
    //  3-1. mbti 결정
    //  3-2. 출력
    for(int i=0; i<4; i++){
        if(sum[i]==20){
            while(sum[i]==20){
                printf("\n%c할래요 %c할래요? (%c하려면 0, %c하려면 1 입력)>> ", mbtioption[i][0], mbtioption[i][1], mbtioption[i][0], mbtioption[i][1]);
                scanf("%d", &temp);
                if(temp == 0){
                    mbti[i] = mbtioption[i][0];
                    break;
                }else if(temp == 1){
                    mbti[i] = mbtioption[i][1];
                    break;
                }else{
                    printf("0 또는 1의 숫자로 입력해주세요.\n");
                }
            }
        }else{
            if(sum[i]>20){
                mbti[i] = mbtioption[i][0];
            }else{
                mbti[i] = mbtioption[i][1];
            }
        }
    }
    // mbti[0] = (sum[0]>=20)? 'E': 'I';
    // mbti[1] = (sum[1]>=20)? 'S': 'N';
    // mbti[2] = (sum[2]>=20)? 'T': 'F';
    // mbti[3] = (sum[3]>=20)? 'J': 'P';

    printf("\nYou are ");
    for(int i=0; i<4; i++){
        printf("%c", mbti[i]);
    }
    printf("\n");

    return 0;
}