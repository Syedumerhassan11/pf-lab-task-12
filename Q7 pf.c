#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j, modRow, modCol, newValue;
    int** array;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    array = (int**)malloc(rows * sizeof(int*));
    if (array == NULL) return 1;

    for (i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
        if (array[i] == NULL) return 1;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    printf("Enter the row and column to modify (0-based index): ");
    scanf("%d %d", &modRow, &modCol);
    printf("Enter the new value: ");
    scanf("%d", &newValue);
    array[modRow][modCol] = newValue;

    printf("The updated 2D array is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}

