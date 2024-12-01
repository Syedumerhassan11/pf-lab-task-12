#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 10001 // Maximum value of Ai as per constraints

void findMostFrequentNumber(int* arr, int n) {
    int freq[MAX_VAL] = {0};
    int maxFreq = 0;
    int result = MAX_VAL;
    int i=0;
    for (; i < n; i++) {
        freq[arr[i]]++;
        if (freq[arr[i]] > maxFreq) {
            maxFreq = freq[arr[i]];
            result = arr[i]; // Update result with the current element
        } else if (freq[arr[i]] == maxFreq) {
            if (arr[i] < result) {
                result = arr[i]; // Update result if the current element is smaller
            }
        }
    }

    printf("%d\n", result);
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int N;
        printf("Enter the number of elements: ");
        scanf("%d", &N);

        int* arr = (int*)malloc(N * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
		printf("Enter the elements of the array:\n");
	int i=0;
	    for (; i < N; i++) {
        scanf("%d", &arr[i]);
        }
		findMostFrequentNumber(arr, N);
		free(arr);
    }
	 return 0;
}

