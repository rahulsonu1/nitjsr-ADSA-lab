#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main() {
    int w[] = {0,2,3,4,5};
    int v[] = {0,3,4,5,6};
    int n=4, W=5, dp[5][6]={0};

    for(int i=1;i<=n;i++)
        for(int j=1;j<=W;j++)
            dp[i][j] = (w[i]<=j) ? max(v[i]+dp[i-1][j-w[i]], dp[i-1][j]) : dp[i-1][j];

    printf("Max value: %d\n", dp[n][W]);
}
