#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    double *fees, totalProfit = 0;

    printf("Enter the total number of points in the facility: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of points.\n");
        return 1;
    }

    fees = (double *)malloc(n * sizeof(double));
    if (fees == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the fee for each point:\n");
    for (i = 0; i < n; i++) {
        printf("Enter fee for point %d: ", i + 1);
        scanf("%lf", &fees[i]);
        if (fees[i] < 0) {
            printf("Invalid fee entered.\n");
            free(fees);
            return 1;
        }
        totalProfit += fees[i];
    }

    printf("Total Profit for the facility: $%.2f\n", totalProfit);

    free(fees);
    return 0;
}

