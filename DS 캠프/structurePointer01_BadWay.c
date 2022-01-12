 #include <stdio.h>
 #include <string.h>

struct userInfo {
    int stuNo;
    char sex;
    char name[10];
    char telNo[15];
};

 int main(void){
    struct userInfo user1, user2, user3, user4;
    char temp[15];
    
    printf("학번 성별(F/M) 이름 전화번호(010-0000-0000)를 입력해주세요\tex) 22100014 M Kang 010-2003-1581\n");

    printf(" > ");
    scanf("%d %c %s %s", &user1.stuNo, &user1.sex, user1.name, user1.telNo);
    strcpy(temp, user1.telNo);
    for(int i=0; i<strlen(user1.telNo); i++){
        user1.telNo[i] = temp[strlen(user1.telNo)-1-i];
    }
    user1.telNo[strlen(user1.telNo)] = '\n';


    printf(" > ");
    scanf("%d %c %s %s", &user2.stuNo, &user2.sex, user2.name, user2.telNo);
    strcpy(temp, user2.telNo);
    for(int i=0; i<strlen(user2.telNo); i++){
        user2.telNo[i] = temp[strlen(user2.telNo)-1-i];
    }
    user2.telNo[strlen(user2.telNo)] = '\n';

    printf(" > ");
    scanf("%d %c %s %s", &user3.stuNo, &user3.sex, user3.name, user3.telNo);
    strcpy(temp, user3.telNo);
    for(int i=0; i<strlen(user3.telNo); i++){
        user3.telNo[i] = temp[strlen(user3.telNo)-1-i];
    }
    user3.telNo[strlen(user3.telNo)] = '\n';

    printf(" > ");
    scanf("%d %c %s %s", &user4.stuNo, &user4.sex, user4.name, user4.telNo);
    strcpy(temp, user4.telNo);
    for(int i=0; i<strlen(user4.telNo); i++){
        user4.telNo[i] = temp[strlen(user4.telNo)-1-i];
    }
    user4.telNo[strlen(user4.telNo)] = '\n';

    printf("%d %c %s %s", user1.stuNo, user1.sex, user1.name, user1.telNo);
    printf("%d %c %s %s", user2.stuNo, user2.sex, user2.name, user2.telNo);
    printf("%d %c %s %s", user3.stuNo, user3.sex, user3.name, user3.telNo);
    printf("%d %c %s %s", user4.stuNo, user4.sex, user4.name, user4.telNo);


    return 0;
 }