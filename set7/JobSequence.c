#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

int cmp(const void *a, const void *b) {
    return ((Job*)b)->profit - ((Job*)a)->profit; // sort by profit (desc)
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), cmp);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;

    int slot[maxDeadline + 1];
    for (int i = 1; i <= maxDeadline; i++) slot[i] = -1;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected Jobs: ");
    for (int i = 1; i <= maxDeadline; i++)
        if (slot[i] != -1) printf("%c ", jobs[slot[i]].id);
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    Job jobs[] = {{'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27}, {'D', 1, 25}, {'E', 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);
    return 0;
}
