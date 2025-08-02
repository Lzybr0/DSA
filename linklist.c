#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void displaylist(struct Node* head);

void insertAtBeginning(struct Node**head, int newData){
    //Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = *head;
    *head = newNode;   
}

void displaylist(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

//Main function
int main() {
    struct Node*head = NULL;

    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    printf("Linked list After inserting at beginning:\n");
    displaylist(head);

    return 0;
}

