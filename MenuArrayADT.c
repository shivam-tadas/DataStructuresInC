#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a, size, c_size;
} arr;

int main() {
    int a_size, run = 1, u_ch, u_ele;

    printf("Enter size of array: ");
    scanf("%d", &a_size);
    while (a_size < 1) {
        printf("Invalid size entered. Please try again.\n");
        printf("Enter size of array: ");
        scanf("%d", &a_size);        
    }

    arr *a1 = (arr*) malloc(sizeof(arr));   // Initialize array ADT
    a1->size = a_size;
    a1->c_size = 0;
    a1->a = (int*) calloc(a_size, sizeof(int));

    while (run) {
        printf("1. Display array\n2. Insert element\n3. Clear array\n4. Exit\nMake a choice: ");
        scanf("%d", &u_ch);
        switch(u_ch) {
            case 1:
                if (a1->c_size == 0) {
                    printf("Array is empty!\n");
                    break;
                }

                for (int i = 0; i < a1->c_size; i++)
                    printf("%d  ", a1->a[i]);   // Print array elements seperated by some space
                printf("\n");
                break;

            case 2:
                if (a1->c_size == a1->size) {
                    printf("Array full. Cannot insert more elements.\n");
                    break;
                }

                printf("Enter element to add in array: ");
                scanf("%d", &u_ele);
                a1->a[(a1->c_size)++] = u_ele;  // Update current size of array, and insert element at corresponding position
                break;

            case 3:
                a1->c_size = 0;
                free(a1->a);
                a1->a = (int*) calloc(a_size, sizeof(int));
                break;

            case 4:
                printf("Exiting...\n");
                run = 0;
                break;

            default:
                printf("Invalid choice entered, please try again.\n");
        }
    }
    free(a1->a);    // Free up used memory
    free(a1);
    return 0;
}