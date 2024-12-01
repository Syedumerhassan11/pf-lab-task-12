#include <stdio.h>
#include <stdlib.h>

float findLargest(float* array, int size) {
    float largest = array[0];
    int i=1;
    for (; i < size; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }
    return largest;
}

int main() {
    int n;
    float* array;
    printf("Enter the number of elements (1 to 100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid input. Number of elements should be between 1 and 100.\n");
        return 1;
    }
    array = (float*)malloc(n * sizeof(float));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter %d floating-point numbers:\n", n);
    int i=0;
    for (; i < n; i++) {
        scanf("%f", &array[i]);
    }
    float largest = findLargest(array, n);
    printf("The largest element is: %.2f\n", largest);

    free(array);

    return 0;
}

