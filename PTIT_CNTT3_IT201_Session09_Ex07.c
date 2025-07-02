
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

// Tạo node mới
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

// In danh sách
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
// Thêm phần tử vào vị trí bất kỳ
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = createNode(value);
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    int index = 0;
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    // Nếu vị trí hợp lệ
    if (current != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Khong hop le\n");
        free(newNode);
    }

    return head;
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
    // In danh sách ban đầu
    printList(head);
    int value, position;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon them: ");
    scanf("%d", &position);
    // Chèn vào vị trí
    head = insertAtPosition(head, value, position);
    // In danh sách sau khi thêm
    printList(head);
    // Giải phóng bộ nhớ
    freeList(head);
    return 0;
}