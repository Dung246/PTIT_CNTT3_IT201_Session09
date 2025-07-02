#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        temp = temp->next;
    }
    printf("->NULL\n");
}
int search(Node* head, int target) {
    while (head != NULL) {
        if (head->data == target)
            return 1; // True
        head = head->next;
    }
    return 0; // False
}
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    // In danh sách
    printList(head);
    // Nhập số nguyên từ người dùng
    int number;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &number);
    // Tìm kiếm và in kết quả
    if (search(head, number))
        printf("True\n");
    else
        printf("False\n");
    // Giải phóng bộ nhớ
    freeList(head);

    return 0;
}