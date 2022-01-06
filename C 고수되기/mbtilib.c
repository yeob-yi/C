#include "mbtilib.h"

char mbtioption[4][2] = {{'E', 'I'}, {'S', 'N'}, {'T', 'F'}, {'J', 'P'}};


void setMBTIQuestion(char* filename, struct mbti_question questions[]){
    FILE *file;
    file = fopen(filename, "r");

    int i=0;
    int qnum;
    char line[200];

    fscanf(file, "%d", &qnum);
    getc(file);

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

}


void runTest(int answer[4][8], struct mbti_question questions[]){
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
            count++;
        }else{
            printf("\n잘못 입력하셨습니다. 다시 입력해주세요.\n");
        }
    }
    printf("\n");
}


void evalTest(struct person* user){
    int temp;
    char mbtioption[4][2] = {{'E', 'I'}, {'S', 'N'}, {'T', 'F'}, {'J', 'P'}};
    int mbti=0;

    for(int i=0; i<4; i++){
        user->sum[i] = 0; // 초기화
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<4; j++){
            user->sum[j] += user->answer[j][i];
        }
    }

    for(int i=0; i<4; i++){
        if(user->sum[i]==20){
            while(user->sum[i]==20){
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
            if(user->sum[i]<20)
                mbti += pow(10, (3-i));
        }
    }

    user->mbti_type = mbti;
}

void printList(int num, struct person* user){
    int option;

    printf("%d. %s - ", num+1, user->testername);
    for(int i=0; i<3; i++){
        option = user->mbti_type / (pow(10, (3-i)));
        option = option%10;
        printf("%c", mbtioption[i][option]);
        user->mbtichar[i]=mbtioption[i][option];
    }
    option = user->mbti_type%10;
    printf("%c", mbtioption[3][option]);
    user->mbtichar[3]=mbtioption[3][option];
    printf("\n");
}

void printResult(struct person* user){
    FILE *file;
    file = fopen("result.txt", "r");

    for(int i=0; i<4; i++){
        printf("%2d  %c ", user->sum[i], mbtioption[i][0]);
        for(int j=0; j<40; j++){
            if(j == 40-user->sum[i]-1 || j == 40-user->sum[i]+1){
                printf("|");
            }else if(j==40-user->sum[i]){
                printf("*");
            }else{
                printf("-");
            }
        }
        printf(" %c  %2d  >>  %c\n", mbtioption[i][1], 40-user->sum[i], user->mbtichar[i]);
    }

    char line[1000];
    printf("%s\n", user->mbtichar);
    while(!feof(file)){
        fgets(line, 1000, file);
        if(strncmp(user->mbtichar, line, 4)==0){
            printf("%s", line+5);
            fgets(line, 1000, file);
            do{
                printf("%s", line);
                fgets(line, 1000, file);
            }while(!isalpha(line[0]));
            break;
        }
    }
    printf("\n\n");
    fclose(file);
}