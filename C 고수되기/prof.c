#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_test{
    char testername[20];
    int answer[4][8];
    int mbti_type;  // 0~15 4자리 2진수 0000 ~ 1111
};
struct st_question{
    int type; // 1~4
    char* common;
    char* q1;
    char* q2;
};
struct st_testset{
    int qcount;
    struct st_question* qlist;
};

void ready(struct st_question q[]);
void run(struct st_test* who, struct st_question q[]);
void eval(struct st_test* who);
void result(struct st_test* who);
char* mbtiname(int n);

int main(){
    struct st_test tester;
    struct st_question qlist[32];
    //tester = malloc()...
    //char testername[20];
    //int answer[4][8];
    //int mbti_type;
    srand(time(0));
    //질문 준비
    ready(qlist);
    //질문 진행
    run(&tester, qlist); // parameter : questionlist, answerarray
    //결과 분석
    eval(&tester); // parameter : answerarray, return : type
    //결과 제시
    result(&tester); // parameter : mbtitype

    return 0;
} 

void ready(struct st_question q[]){
   	FILE* file;
	file = fopen("q.txt", "r");
	int qcount=32;
	char line[200];
	for(int i=0;i<qcount;i++){
		fgets(line, 200, file);
		if(line[strlen(line)-1]=='\n')
			line[strlen(line)-1] = '\0';
		q[i].q1 = (char*) malloc(sizeof(char)*(strlen(line)+1));
		strcpy(q[i].q1, line);
		fgets(line, 200, file);
		if(line[strlen(line)-1]=='\n')
			line[strlen(line)-1] = '\0';
		q[i].q2 = (char*) malloc(sizeof(char)*(strlen(line)+1));
		strcpy(q[i].q2, line);
	}
	fclose(file); 
}

void run(struct st_test* who, struct st_question q[]){
    printf("Test begins.\n");
    printf("Your answer is..\n");
    for(int i=0;i<32;i++){
        int row = i%4;
        int col = i/4;
        //who->answer[row][col] = rand()%6;
        printf("문장1 : %s\n", q[i].q1);
        printf("문장2 : %s\n", q[i].q2);
        printf("Enter 0~5 >> ");
        scanf("%d", &(who->answer[row][col]));
        //printf("%2d", who->answer[row][col]);
    }
    printf("\nTest ended.\n");
}
void eval(struct st_test* who){
    int count[4]={0};
    int type=0;
    for(int i=0;i<32;i++){
        int row = i%4;
        int col = i/4;
        count[row] += who->answer[row][col];
    }
    for(int i=0; i<4; i++) 
        if(count[i]>=20)
            type +=  1<<i;
    printf("Type : %d\n", type);
    who->mbti_type = type;
}
void result(struct st_test* who){
    printf("You are %s.\n", mbtiname(who->mbti_type));
}
char* mbtiname(int n){
    char* name = (char*)malloc(sizeof(char)*5);
    if(n & (1<<3)) name[0]='E'; else name[0]='I'; 
    if(n & (1<<2)) name[1]='S'; else name[1]='N'; 
    if(n & (1<<1)) name[2]='T'; else name[2]='F'; 
    if(n & (1<<0)) name[3]='J'; else name[3]='P'; 
    name[4] = '\0';
    return name;    
}



