#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct person{
    char testername[20];
    int answer[4][8];
    int mbti_type;  // 0~15 4자리 2진수 0000 ~ 1111
};
struct mbti_question{
    int type; // 1~4
    char* question;
    char* answer5;
    char* answer0;
};
struct testset{
    int qcount;
    struct mbti_question* qlist;
};

// void getquestions(struct testset questions);
void getquestions(struct mbti_question questions[]);
void run(struct mbti_question questions[], int answer[4][8]); // parameter : questionlist, answerarray
int eval(int answer[4][8]); // parameter : answerarray, return : mbti
void result(int mbtinum, char mbti[]); // parameter : mbtitype
void result_explain(char mbti[]);

int main(){
    struct person profile;
    struct testset set;
    struct mbti_question questionlist[32];
    int answer[4][8] = {0};
    int mbti_type;
    char mbti[5];
    
    // 1. 질문 준비
    // getquestions(set);
    getquestions(questionlist);
    
    // 2. 질문 진행
    run(questionlist, answer); // parameter : questionlist, answerarray

    // 3. 결과 분석
    mbti_type = eval(answer); // parameter : answerarray, return : mbti

    // 4. 결과 제시
    result(mbti_type, mbti); // parameter : mbtitype
    // printf("%s", mbti);
    result_explain(mbti);
    
    return 0;
}

void getquestions(struct mbti_question questions[]){
    FILE *file;
    file = fopen("qlist.txt", "r");

    int i=0;
    int qnum;
    char line[200];

    fscanf(file, "%d", &qnum);
    fgetc(file);

    while(i<qnum){
        fscanf(file, "%d", &questions[i].type); // type
        fgetc(file);

        fgets(line, 200, file); // question
        if(line[strlen(line)-1]=='\n')
            line[strlen(line)-1] = '\0';
        questions[i].question = (char*) malloc(sizeof(char)*(strlen(line)+1));
        strcpy(questions[i].question, line);

        fgets(line, 200, file); // answer5
        if(line[strlen(line)-1]=='\n')
            line[strlen(line)-1] = '\0';
        questions[i].answer5 = (char*) malloc(sizeof(char)*(strlen(line)+1));
        strcpy(questions[i].answer5, line);

        fgets(line, 200, file); // answer0
        if(line[strlen(line)-1]=='\n')
            line[strlen(line)-1] = '\0';
        questions[i].answer0 = (char*) malloc(sizeof(char)*(strlen(line)+1));
        strcpy(questions[i].answer0, line);

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
            if(sum[i]<20)
                mbti += pow(10, (3-i));
        }
    }
    // printf("%d\n", mbti);
    return mbti;
};

void result(int mbtinum, char mbtichar[]){
    char mbtioption[4][2] = {{'E', 'I'}, {'S', 'N'}, {'T', 'F'}, {'J', 'P'}};
    int option;
    printf("You are ");
    for(int i=0; i<3; i++){
        option = mbtinum / (pow(10, (3-i)));
        option = option%10;
        printf("%c", mbtioption[i][option]);
        mbtichar[i]=mbtioption[i][option];
    }
    option = mbtinum%10;
    printf("%c", mbtioption[3][option]);
    mbtichar[3]=mbtioption[3][option];
    printf("\n\n");

};

void result_explain(char mbti[]){
    FILE *file;
    file = fopen("result.txt", "r");

    char line[1000];
    while(!feof(file)){
        fgets(line, 1000, file);
        if(strncmp(mbti, line, 4)==0){
            printf("%s", line+5);
            fgets(line, 1000, file);
            do{
                printf("%s", line);
                fgets(line, 1000, file);
            }while(!isalpha(line[0]));
            break;
        }
    }

    fclose(file);
}