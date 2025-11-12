#include <stdio.h>

int maxProfit = 0;

void knapsack(int n, int wt[], int val[], int W, int i, int currWt, int currVal) {
    if (i == n) {
        if (currVal > maxProfit && currWt <= W)
            maxProfit = currVal;
        return;
    }

    // Include the current item
    if (currWt + wt[i] <= W)
        knapsack(n, wt, val, W, i + 1, currWt + wt[i], currVal + val[i]);

    // Exclude the current item
    knapsack(n, wt, val, W, i + 1, currWt, currVal);
}

int main() {
    int n = 4, W = 7;
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};

    knapsack(n, wt, val, W, 0, 0, 0);

    printf("Maximum Profit: %d\n", maxProfit);
    return 0;
}
