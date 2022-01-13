#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkedList* makeList() {
    LinkedList* new_list = (LinkedList*)malloc(sizeof(LinkedList));
    new_list->head = NULL;
    
    return new_list;
}

int insert(LinkedList *plist, int data) {
    // 1. new_node 생성
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) // 1.1 new_node malloc 잘못되었을 경우
        return 0;
    new_node->data = data; 
    new_node->next = NULL;  // 1.2 new_node의 n-ext는 NULL 가리킴

    // 2. new_node를 마지막 node로 저장
    if(plist->head==NULL)  // 2.1 plist의 head가 NULL == 현재 node 0개
        plist->head = new_node;
    else{  // 2.2 node가 0개가 아닌 경우(=1개라도 있을 경우)
        Node* cur = plist->head;  // 2.2.1 Node* cur 선언 (지금 보고 있는 node)
        while(cur->next !=NULL)   // 2.2.2 next가 NULL이 아닌 경우 -> 마지막 노드가 아닌 경우
            cur = cur->next;
        cur->next = new_node;
    }

    return 1;
}

int removeData(LinkedList* plist, int data){
    // 1. 노드가 하나도 없을 때 -> remove할 node 없으므로 1 반환
    if(plist->head == NULL)
        return 1;
    
    // 2. cur, pre 노드 생성
    Node* cur = plist->head;
    Node* pre = NULL;

    // 3. plist의 끝에 닿을 때까지 반복 -> cur을 하나씩 옮겨가며 지우고 싶은 data를 찾음
    while(cur!=NULL){
        if(cur->data == data)
            break;
        pre = cur;
        cur = cur->next;
    }

    // 4. 
    if(cur == NULL)  // 지우고 싶은 node를 찾지 못한 경우
        return 0;
    else if(cur->data == data){  // 지우고 싶은 node를 찾은 경우
        if(pre==NULL)  // 지우고 싶은 node가 head인 경우
            plist->head = cur->next;
        else
            pre->next = cur->next;
    }

    free(cur);
    return 1;
}

void printList(LinkedList* plist){
    Node* cur = plist->head;

    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void freeList(LinkedList* plist){
    Node* cur = plist->head;
    Node* del = plist->head;

    while(cur != NULL){
        del = cur;
        cur = cur->next;
        free(del);
    }

    plist->head = NULL;
}