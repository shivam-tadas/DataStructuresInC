#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int capacity, *q, l_ptr, r_ptr;
} queue;

int main() {
    int exit = 0, sz, ch, u_ele;
    printf("Enter capacity of queue: ");
    scanf("%d", &sz);
    queue *q1 = (queue*) malloc(sizeof(queue));
    q1->q = (int*) calloc(sz, sizeof(int));
    q1->capacity = sz + 1;
    q1->l_ptr = 0;  // Set pointers to current state of q
    q1->r_ptr = 0;
    printf("Queue of size %d created.\n", sz);
    while (!exit) {
        printf("Select an option:\n1. Enqueue\n2. Dequeue\n3. View Queue\n4. Exit\nYour Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                if ((q1->r_ptr + 1) % q1->capacity == q1->l_ptr) {  // Queue full whenever left is just "behind" right
                    printf("Queue full!\n");
                    break;
                }

                printf("Enter element to enqueue: ");
                scanf("%d", &u_ele);

                q1->q[q1->r_ptr] = u_ele;
                q1->r_ptr = (q1->r_ptr + 1) % q1->capacity; // Use circular queue
                break;

            case 2:
                if (q1->l_ptr == q1->r_ptr) {
                    printf("Queue empty!\n");
                    break;
                }

                printf("Element dequeued: %d\n", q1->q[q1->l_ptr]);
                q1->l_ptr = (q1->l_ptr + 1) % q1->capacity; // "delete" dequeued element by moving left pointer ahead
                break;

            case 3:
                if (q1->l_ptr == q1->r_ptr) {
                    printf("Queue empty!\n");
                    break;
                }

                int lp1 = q1->l_ptr, lp2 = q1->r_ptr;
                while (lp1 != lp2) {
                    printf("%d\t", q1->q[lp1]); // Iterate over existing circular queue
                    lp1 = (lp1 + 1) % q1->capacity;
                }
                printf("\n");
                break;

            case 4:
                exit = 1;
                printf("Exiting...\n");
                break;

            default:
                printf("Incorrect option chosen.\n");
        }
    }
    free(q1->q);
    free(q1);
}