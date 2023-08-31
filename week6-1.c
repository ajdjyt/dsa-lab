#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void displayList(struct node *head){
    struct node *current = head;
    printf("Elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct node* insertBeginning(struct node *head, int ele){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL){
        head->prev = newnode;
    }

    return newnode;
}

struct node* insertEnd(struct node *head, int ele){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->next = NULL;

    if (head == NULL){
        newnode->prev = NULL;
        return newnode;
    }

    struct node *current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;

    return head;
}

struct node* deleteElement(struct node *head, int ele){
    struct node *current = head;
    while (current != NULL && current->data != ele){
        current = current->next;
    }

    if (current == NULL){
        printf("Element not found.\n");
        return head;
    }

    if (current->prev != NULL){
        current->prev->next = current->next;
    } 
    else{
        head = current->next;
    }

    if (current->next != NULL){
        current->next->prev = current->prev;
    }

    free(current);
    return head;
}

void main(){
    struct node *head = NULL;
    int choice, ele;

    do{
        printf("\nDoubly Linked List Operations\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                displayList(head);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &ele);
                head = insertBeginning(head, ele);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &ele);
                head = insertEnd(head, ele);
                break;
            case 4:
                printf("Enter element: ");
                scanf("%d", &ele);
                head = deleteElement(head, ele);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice..\n");
        }

    } while (choice != 5);

    struct node *current = head;
    while (current != NULL){
        struct node *temp = current;
        current = current->next;
        free(temp);
    }
}