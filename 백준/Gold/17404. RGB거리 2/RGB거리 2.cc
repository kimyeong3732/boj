#include <iostream>

using namespace std;

int main() {
    int n;
    int cost[1000][3];
    int result = 1000001;
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            cin >> cost[i][j];
    
    for(int i=0; i<3; i++) {
        int dp[1000][3];
        
        dp[0][i] = cost[0][i];
        
        for(int j=0; j<3; j++) {
            if(i != j)
                dp[1][j] = dp[0][i] + cost[1][j];
            
            else
                dp[1][j] = 1000001;
        }
        
        for(int j=2; j<n; j++) {
            dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + cost[j][0];
            dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + cost[j][1];
            dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + cost[j][2];
        }
        
        for(int j=0; j<3; j++)
            if(i != j)
                result = min(result, dp[n-1][j]);
    }
    
    cout << result;
    
    return 0;
}