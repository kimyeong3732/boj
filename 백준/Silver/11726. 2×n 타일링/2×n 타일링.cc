#include <cstdio>

int main() {
    int n;
    int dp[1000] = {1, 2};
    
    scanf("%d", &n);
    
    for(int i=2; i<n; i++) {
        dp[i] = dp[i-2] + dp[i-1];
        if(dp[i] >= 10007)
            dp[i] %= 10007;
    }
    
    printf("%d\n", dp[n-1]);
    
    return 0;
}