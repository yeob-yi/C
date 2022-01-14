 #include <stdio.h>
 #include <string.h>

struct user {
    int stuNo;
    char sex;
    char name[10];
    char telNo[15];
};

 int main(void){
    struct user userInfo[4];
    char temp[15];

    printf("학번 성별(F/M) 이름 전화번호(010-0000-0000)를 입력해주세요\tex) 22100014 M Kang 010-2003-1581\n");

    for(int i=0; i<4; i++){
        printf(" > ");
        scanf("%d %c %s %s", &userInfo[i].stuNo, &userInfo[i].sex, userInfo[i].name, userInfo[i].telNo);
        strcpy(temp, userInfo[i].telNo);
        for(int j=0; j<strlen(temp); j++){
            userInfo[i].telNo[j] = temp[strlen(temp)-1-j];
        }
        (userInfo[i].telNo)[strlen(userInfo[i].telNo)] = '\n';
    }

    for(int i=0; i<4; i++){
        printf("%d %c %s %s", userInfo[i].stuNo, userInfo[i].sex, userInfo[i].name, userInfo[i].telNo);
    }

    return 0;
 } 