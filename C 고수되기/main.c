#include <stdio.h>
#include "mbtilib.h"

// void getquestions(struct testset questions);
// void getquestions(struct mbti_question questions[]);
// void run(struct mbti_question questions[], int answer[4][8]); // parameter : questionlist, answerarray
// int eval(int answer[4][8], int sum[]); // parameter : answerarray, return : mbti
// void result(int sum[], int mbtinum, char mbti[]); // parameter : mbtitype
// void result_explain(char mbti[]);

int main(){
    struct mbti_question questionlist[32]; // 질문목록
    struct person *profile[50]; // 유저정보
    int usernum = 0; // 현재 유저 수
    int result;

    int menu=0;
    char menuchar[4][100] = {"* 질문 진행 *", "* 결과 보여주기 *", "* 종료 *"};
    
    // 1. 질문 준비
    setMBTIQuestion("qlist.txt", questionlist);
    
    // 2. 메뉴 출력
    while(menu!=3){
    //   2-0. 메뉴 입력받기
        printf("*** 메뉴 선택 ***\n 1.질문 진행 2.결과 보여주기 3.종료\n");
        scanf("%d", &menu);
        printf("\n%s\n", menuchar[menu-1]);
    //   2-1. (1 입력시) 질문 진행
    //     1) 사용자 생성
    //     2) 이름 입력받기
    //     3) 32번 반복 : 질문, 답변 저장
    //     4) 결과 계산
        if(menu==1){
            
            profile[usernum] = (struct person*) malloc(sizeof(struct person));
            printf("이름을 입력하세요 >> ");
            scanf("%s", profile[usernum]->testername);
            runTest(profile[usernum]->answer, questionlist);
            evalTest(profile[usernum]);
            usernum++;
    //   2-2. (2 입력시) 결과 보여주기
        }else if(menu==2){
            for(int i=0; i<usernum; i++){
                printList(i, profile[i]);
            }
            printf("결과를 확인하고 싶은 번호 입력 >>");
            scanf("%d", &result);
            printResult(profile[result-1]);
    //   2-3. (3 입력시) 종료
        }else if(menu==3){
            break;
        }
    }

    return 0;
}