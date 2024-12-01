#include <stdio.h>
#include <stdlib.h>
void insertElement(int** array, int* size, int* capacity, int pos, int element) {
    if (*size == *capacity) {
        *capacity *= 2;
        *array = (int*)realloc(*array, (*capacity) * sizeof(int));
        if (*array == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
    }
    int i=*size;
    for (; i > pos; i--) {
        (*array)[i] = (*array)[i - 1];
}
    (*array)[pos] = element;
    (*size)++;
}
void deleteElement(int* array, int* size, int pos) {
    if (*size == 0 || pos >= *size) {
        printf("Deletion not possible. Invalid position.\n");
        return;
    }
    int i=pos;
    for (; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }
    (*size)--;
}

void performOperations(int* array, int size, int capacity) {
    int numOps;
    printf("Enter the number of operations: ");
    scanf("%d", &numOps);
	int i=0;
    for (; i < numOps; i++) {
        char op;
        int pos, element;

        printf("Enter operation (I for Insert, D for Delete) and position: ");
        scanf(" %c %d", &op, &pos);

        if (op == 'I') {
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            insertElement(&array, &size, &capacity, pos, element);
        } else if (op == 'D') {
            deleteElement(array, &size, pos);
        } else {
            printf("Invalid operation.\n");
        }
        printf("Array after operation: ");
        int j=0;
        for (; j < size; j++) {
            printf("%d ", array[j]);
        }
        printf("\n");
    }
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N;
        printf("Enter the number of elements in the sequence: ");
        scanf("%d", &N);
        int capacity = N > 4 ? N : 4;
        int* array = (int*)malloc(capacity * sizeof(int));
        if (array == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter the elements of the array:\n");
        int i=0;
        for (; i < N; i++) {
            scanf("%d", &array[i]);
        }

        performOperations(array, N, capacity);
        free(array);
    }
return 0;
}

