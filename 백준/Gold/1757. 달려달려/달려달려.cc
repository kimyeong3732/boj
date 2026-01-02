#include <iostream>

using namespace std;

int dp[10001][501];

int main() {
    int n, m;
    
    cin >> n >> m;
    
    for(int i=1; i<=m; i++)
        dp[0][i] = -1;
    
    for(int i=1; i<=n; i++) {
        int num;
        
        cin >> num;
        
        for(int j=0; j<m; j++)
            if(dp[i-1][j] >= 0)
                dp[i][j+1] = dp[i-1][j] + num;
        
        dp[i][0] = dp[i-1][0];
        
        for(int j=1; i-j>=0 && j<=m; j++)
            dp[i][0] = max(dp[i][0], dp[i-j][j]);
    }
    
    cout << dp[n][0];
    
    return 0;
}