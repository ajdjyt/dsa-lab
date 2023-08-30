#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *head){
    struct node *tmp = head;
    printf("Linked List Elements: ");
    while (tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

struct node* insertBeginning(struct node *head, int element){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = head;
    return newnode;
}

struct node* insertEnd(struct node *head, int element){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;

    if (head == NULL){
        return newnode;
    }

    struct node *tmp = head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newnode;
    return head;
}

struct node* deleteElement(struct node *head, int element){
    if (head == NULL){
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (head->data == element){
        struct node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }

    struct node *tmp = head;
    while (tmp->next != NULL && tmp->next->data != element) {
        tmp = tmp->next;
    }

    if (tmp->next == NULL){
        printf("Element %d not found in the list.\n", element);
    } 
    else{
        struct node *del = tmp->next;
        tmp->next = tmp->next->next;
        free(del);
    }
    return head;
}

void main(){
    struct node *head = NULL; 
    int choice, element;

    do{
        printf("Linked List Operations\n");
        printf("1. Display \n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &element);
                head = insertBeginning(head, element);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &element);
                head = insertEnd(head, element);
                break;
            case 4:
                printf("Enter element: ");
                scanf("%d", &element);
                head = deleteElement(head, element);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    struct node *tmp = head;
    while (tmp != NULL){
        struct node *tmp = tmp;
        tmp = tmp->next;
        free(tmp);
    }
}