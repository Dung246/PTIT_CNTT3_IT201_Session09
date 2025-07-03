#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;
// Hàm tạo node mới
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

// Hàm in danh sách liên kết
void printList(Node* head) {
    printf("Danh sach lien ket don :\n");
    while (head != NULL) {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Hàm giải phóng bộ nhớ
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    // Tạo danh sách gồm 5 phần tử
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    // In danh sách
    printList(head);
    // Giải phóng bộ nhớ
    freeList(head);

    return 0;
}
