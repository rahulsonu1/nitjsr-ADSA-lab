#include <stdio.h>

void coinChange(int coins[], int n, int amount) {
    printf("Coins used: ");
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            printf("%d ", coins[i]);
        }
    }
    printf("\n");
}

int main() {
    int coins[] = {10, 5, 2, 1}; // coin denominations
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount;

    printf("Enter amount: ");
    scanf("%d", &amount);

    coinChange(coins, n, amount);
    return 0;
}
