#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct person{
    char testername[20];
    int answer[4][8];
    int sum[4];
    int mbti_type;  // 0~15 4자리 2진수 0000 ~ 1111
    char mbtichar[4];
};
struct mbti_question{
    int type; // 1~4
    char* question;
    char* answer5;
    char* answer0;
};

void setMBTIQuestion(char* filename, struct mbti_question questions[]);
void runTest(int answer[4][8], struct mbti_question questions[]);
void evalTest(struct person* user);

void printList(int num, struct person* user);
void printResult(struct person* user);
// void printGraph(struct st_test* who);

