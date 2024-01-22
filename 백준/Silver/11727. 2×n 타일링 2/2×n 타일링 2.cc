#include <cstdio>

int main() {
    int n;
    int dp[1000] = {1, 3};
    
    scanf("%d", &n);
    
    for(int i=2; i<n; i++) {
        dp[i] = dp[i-1] + dp[i-2]*2;
        
        if(dp[i] >= 10007)
            dp[i] %= 10007;
    }
    
    printf("%d\n", dp[n-1]);
    
    return 0;
}