#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* takeInput() {
    int data;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter data for the list (-1 to stop):\n");
    scanf("%d", &data);

    while (data != -1) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Error: Memory allocation failed!\n");
            exit(1);
        }
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
         
            head = newNode;
            tail = newNode;
        } else {
           
            tail->next = newNode;
          
            tail = tail->next;
        }
        scanf("%d", &data);
    }
    return head;
}
void printList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf(" Your Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Creating a new linked list from user input ---\n");
    struct Node* head = takeInput();
    printList(head);
    return 0;
}
