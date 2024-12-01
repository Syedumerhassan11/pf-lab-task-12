#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_students, i, j;
	printf("Enter the number of students: ");
    scanf("%d", &num_students);
    int** grades = (int**)malloc(num_students * sizeof(int*));
    int* num_grades = (int*)malloc(num_students * sizeof(int));

    if (grades == NULL || num_grades == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (i = 0; i < num_students; i++) {
        printf("\nEnter the number of grades for student %d: ", i + 1);
        scanf("%d", &num_grades[i]);
        grades[i] = (int*)malloc(num_grades[i] * sizeof(int));
        if (grades[i] == NULL) {
            printf("Memory allocation failed for student %d.\n", i + 1);
            return 1;
        }

        printf("Enter the grades for student %d:\n", i + 1);
        for (j = 0; j < num_grades[i]; j++) {
            printf("Grade %d: ", j + 1);
            scanf("%d", &grades[i][j]);
        }
    }
    printf("\nEntered grades:\n");
    for (i = 0; i < num_students; i++) {
        printf("Student %d: ", i + 1);
        for (j = 0; j < num_grades[i]; j++) {
            printf("%d ", grades[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < num_students; i++) {
        free(grades[i]);
    }
    free(grades);
    free(num_grades);

    return 0;
}

