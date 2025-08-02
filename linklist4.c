#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void displaylist(struct Node* head);
void insertAtEnd(struct Node** head, int newData);
void deleteAtEnd(struct Node** head);

//Main function
int main() {
    struct Node*head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
   
    printf("Linked list After inserting at end:\n");
    displaylist(head);

    deleteAtEnd(&head);
    printf("Link list After Deletetion at end:\n");
    displaylist(head);
    
    return 0;
}

void insertAtEnd(struct Node** head, int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;   
    if (*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}


void displaylist(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void deleteAtEnd(struct Node** head){
    if (*head == NULL){
        printf("List is empty. Cannot delete .\n");
        return;
    }
    
    struct Node* temp = *head;
    if (temp -> next == NULL){
        printf("Delete element: %d\n", temp -> data);
        free(temp);
        *head = NULL;
        return;
    }

    while (temp -> next -> next != NULL) {
        temp = temp -> next;
    }
    printf("Deleted element: %d\n",temp -> next -> data);
    free(temp -> next);
    temp -> next = NULL;
}
