#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}Node;
Node* createNode(int value) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL) {
        printf("Khong the cap phat bo nho");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void printfList(Node* head) {
    Node*temp =head;
    while(temp!=NULL) {
        printf("%d ",temp->data);
        if(temp->next!=NULL) {
            printf("->");
        }
        temp=temp->next;
    }
    printf("->NULL\n");
}
void printIndex(Node* head) {
    int index=1;
    while(head!=NULL) {
        printf("Node %d : %d\n",index,head->data);
        head=head->next;
        index++;
    }
}
void freeList(Node* head) {
     Node* temp;
    while(head!=NULL) {
        temp=head;
        head=head->next;
        free(temp);
    }
}
int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printfList(head);
    printIndex(head);
    freeList(head);
    return 0;
}