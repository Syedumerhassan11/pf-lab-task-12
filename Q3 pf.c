#include <stdio.h>
#include <stdlib.h>

void addNumber(float** array, int* size, int* capacity, float number) {
    if (*size == *capacity) {
        *capacity *= 2;
        *array = (float*)realloc(*array, (*capacity) * sizeof(float));
        if (*array == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
    }
    (*array)[(*size)++] = number;
}

void displayArray(float* array, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements:\n");
    int i=0;
    for (; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

void removeLastNumber(float** array, int* size, int* capacity) {
    if (*size == 0) {
        printf("Array is already empty.\n");
        return;
    }
    (*size)--;
    if (*size < *capacity / 4) {
        *capacity /= 2;
        *array = (float*)realloc(*array, (*capacity) * sizeof(float));
        if (*array == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
    }
    printf("Last number removed. Array size reduced if necessary.\n");
}

int main() {
    int capacity = 4;
    int size = 0; 
    int choice;
    float number;
    float* array = (float*)malloc(capacity * sizeof(float));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a new number\n");
        printf("2. Display all numbers\n");
        printf("3. Remove the last number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a floating-point number: ");
                scanf("%f", &number);
                addNumber(&array, &size, &capacity, number);
                break;

            case 2:
                displayArray(array, size);
                break;

            case 3:
                removeLastNumber(&array, &size, &capacity);
                break;

            case 4:
                free(array);
                printf("Memory freed. Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

