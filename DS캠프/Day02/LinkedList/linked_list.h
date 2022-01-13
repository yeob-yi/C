#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct linked_list {
    Node* head;
} LinkedList;

LinkedList* makeList();
int insert(LinkedList *plist, int data);
int removeData(LinkedList* plist, int data);
void printList(LinkedList* plist);
void freeList(LinkedList* plist);

#endif