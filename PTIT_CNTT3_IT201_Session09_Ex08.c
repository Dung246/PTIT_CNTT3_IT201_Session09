#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho dong\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// In danh sách liên kết
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
// Xóa node tại vị trí bất kỳ
Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) return NULL;
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    int index = 0;
    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }
    if (current != NULL && current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    } else {
        printf("Khong hop le\n");
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
    // Nhập vị trí muốn xóa
    int position;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &position);
    // Xóa phần tử tại vị trí
    head = deleteAtPosition(head, position);
    // In danh sách
    printList(head);
    // Giải phóng bộ nhớ
    freeList(head);
    return 0;
}
