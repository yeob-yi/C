#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 200

struct mbti_question{
    int type;
    char question[SIZE];
    char answer5[SIZE];
    char answer0[SIZE];
}questionlist[50];

/*
struct st_question{
    int type;
    char* common;
    char* q1;
    char* q2;
};

struct st_testset{
    int qcount;
    strcut st_question* qlist;
};
*/

void getquestions(struct mbti_question questions[]);
void run(struct mbti_question questions[], int answer[4][8]); // parameter : questionlist, answerarray
int eval(int answer[4][8]); // parameter : answerarray, return : mbti
void result(int mbti); // parameter : mbtitype

int main(){
    int answer[4][8] = {0};
    int mbti_type;
    
    // 1. 질문 준비
    getquestions(questionlist);
    
    // 2. 질문 진행
    run(questionlist, answer); // parameter : questionlist, answerarray

    // 3. 결과 분석
    mbti_type = eval(answer); // parameter : answerarray, return : mbti

    // 4. 결과 제시
    result(mbti_type); // parameter : mbtitype
    
    return 0;
}

void getquestions(struct mbti_question questions[]){
    int num;
    int i=0;
    FILE *file;

    file = fopen("qlist.txt", "r");
    fscanf(file, "%d", &num);
    fgetc(file);
    
    while(!feof(file)){
        fscanf(file, "%d", &questions[i].type);
        fgetc(file);
        fgets(questions[i].question, sizeof(char)*SIZE, file);
        fgets(questions[i].answer5, sizeof(char)*SIZE, file);
        questions[i].answer5[(strlen(questions[i].answer5))-1] = '\0';
        fgets(questions[i].answer0, sizeof(char)*SIZE, file);
        i++;
    }

    fclose(file);
}

void run(struct mbti_question questions[], int answer[4][8]){
    int count=0;
    int temp;

    while(count<32){
        printf("\n[%02d/32] %s\n", count+1, questions[count].question);
        printf("⌃ 5   %s\n", questions[count].answer5);
        for(int i=4; i>0; i--){
            printf("⌃ %d ⌄\n", i);
        }
        printf("  0 ⌄ %s\n", questions[count].answer0);
        printf("숫자 입력 >> ");
        scanf("%d", &temp);
        if(temp>=0 && temp<=5){
            answer[count%4][count/4] = temp;
            // printf("answer[%d][%d]에 %d 저장됨\n", count%4, count/4, answer[count%4][count/4]);
            count++;
        }else{
            printf("\n잘못 입력하셨습니다. 다시 입력해주세요.\n");
        }
    }

    // for(int i=0; i<32; i++){
    //     printf("%d ", answer[i%4][i/4]);
    // }
    
    printf("\n");

};

int eval(int answer[4][8]){
    int temp;
    int sum[4]={0};
    char mbtioption[4][2] = {{'E', 'I'}, {'S', 'N'}, {'T', 'F'}, {'J', 'P'}};
    int mbti=0;


    for(int i=0; i<8; i++){
        for(int j=0; j<4; j++){
            sum[j] += answer[j][i];
            // printf("sum[%d]에 answer[%d][%d] 더해져서 %d\n", j, j, i, sum[j]);

        }
    }

    for(int i=0; i<4; i++){
        if(sum[i]==20){
            while(sum[i]==20){
                printf("\n%c할래요 %c할래요? (%c하려면 0, %c하려면 1 입력)>> ", mbtioption[i][0], mbtioption[i][1], mbtioption[i][0], mbtioption[i][1]);
                scanf("%d", &temp);
                if(temp == 0 || temp == 1){
                    mbti += pow(10, (3-i))*temp;
                    break;
                }else{
                    printf("0 또는 1의 숫자로 입력해주세요.\n");
                }
            }
        }else{
            if(sum[i]>20)
                mbti += pow(10, (3-i));
        }
    }
    // printf("%d\n", mbti);
    return mbti;
};

void result(int mbti){
    char mbtioption[4][2] = {{'E', 'I'}, {'S', 'N'}, {'T', 'F'}, {'J', 'P'}};
    int option;
    printf("You are ");
    for(int i=0; i<3; i++){
        option = mbti/(int)(pow(10, (3-i)));
        printf("%c", mbtioption[i][option]);
    }
    printf("%c", mbtioption[3][option]);
    printf("\n");

};
