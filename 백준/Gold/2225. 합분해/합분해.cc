#include <iostream>

using namespace std;

long long dp[201][201];

int main() {
    int n, k;
    
    cin >> n >> k;
    
    for(int i=0; i<=n; i++)
        dp[1][i] = 1;
    
    for(int i=2; i<=k; i++) {
        for(int j=0; j<=n; j++) {
            for(int k=0; k<=j; k++) {
                dp[i][j] += dp[i-1][k];
            }
            
            dp[i][j] %= 1000000000;
        }
    }
    
    cout << dp[k][n];
    
    return 0;
}