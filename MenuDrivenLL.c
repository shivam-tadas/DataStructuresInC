#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int n;
    struct node *next;
} node;

void viewLL(node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    node *tmp = head;
    while (tmp != NULL) {   // Print linked list iteratively
        printf("%d\t", tmp->n);
        tmp = tmp->next;
    }
    printf("\n");
}

void addToLL(node **head, int new) {
    if (*head == NULL) {
        *head = (node*) malloc(sizeof(node));
        (*head)->n = new;
        (*head)->next = NULL;
        return;
    }

    node *tmp = *head, *newNode = (node*) malloc(sizeof(node));
    newNode->n = new;
    newNode->next = NULL;
    while (tmp->next != NULL) {
        tmp = tmp->next;    // Traverse to last node
    }
    tmp->next = newNode;
}

void deleteLastNode(node **head) {
    if (*head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        printf("Deleted node: %d\n", (**head).n);
        free(*head);
        *head = NULL;
        return;
    }

    if ((*head)->next == NULL) {
        node *tmp = *head;
        *head = NULL;
        free(tmp);
        return;
    }

    node *tmp = *head, *prev = NULL;
    while (tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    printf("Deleting node: %d\n", prev->next->n);
    prev->next = NULL;
    free(tmp);
}

void freeLL(node *head) {
    if (head == NULL) return;
    
    freeLL(head->next);
    free(head);
}

int main() {
    int u_val, state = 1, option;
    node *head = NULL;
    printf("Empty linked list initialized.\n");
    while (state) {
        printf("Choose an option\n1. View\n2. Add\n3. Delete\n4. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                viewLL(head);
                break;
            case 2:
                printf("Enter value for new node: ");
                scanf("%d", &u_val);
                addToLL(&head, u_val);
                break;
            case 3:
                deleteLastNode(&head);
                break;
            case 4:
                state = 0;
                printf("Exiting program...\n");
                break;
            default:
                printf("Please enter a valid option\n");
        }
    }
    freeLL(head);   // Remove linked list from memory after use
}
