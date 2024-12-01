#include <stdio.h>
#include <stdlib.h>

void makeArrayEven(int* array, int size) {
	int i=0;
    for (; i < size; i++) {
        if (array[i] % 2 != 0) {
            array[i]--;
        }
    }
}

int main() {
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    makeArrayEven(array, size);
    printf("\nModified array (only even numbers):\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);

    return 0;
}

