#include <iostream>

using namespace std;

int dp[1000][2][3];

int main() {
    int n;
    
    cin >> n;
    
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    dp[0][0][1] = 1;
    
    for(int i=1; i<n; i++) {
        dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2];
        dp[i][0][0] %= 1000000;
        
        dp[i][0][1] = dp[i-1][0][0];
        dp[i][0][1] %= 1000000;
        
        dp[i][0][2] = dp[i-1][0][1];
        dp[i][0][2] %= 1000000;
        
        dp[i][1][0] = dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2] + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2];
        dp[i][1][0] %= 1000000;
        
        dp[i][1][1] = dp[i-1][1][0];
        dp[i][1][1] %= 1000000;
        
        dp[i][1][2] = dp[i-1][1][1];
        dp[i][1][2] %= 1000000;
    }
    
    int result = 0;
    
    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            result += dp[n-1][i][j];
            result %= 1000000;
        }
    }
    
    cout << result;
    
    return 0;
}