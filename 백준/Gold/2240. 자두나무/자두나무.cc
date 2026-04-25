#include <iostream>

using namespace std;

int dp[3][1001][32];
int input[1001];

int main() {
    int t, d;
    
    cin >> t >> d;
    
    for(int i=1; i<=t; i++)
        cin >> input[i];
    
    if(input[1] == 1)
        dp[1][1][1] = 1;
    else
        dp[2][1][2] = 1;
    
    for(int i=2; i<=t; i++) {
        for(int j=1; j<=d+1; j++) {
            if(input[i] == 1) {
                dp[1][i][j] = max(dp[1][i-1][j], dp[2][i-1][j-1]) + 1;
                dp[2][i][j] = max(dp[1][i-1][j-1], dp[2][i-1][j]);
            }
            
            else {
                dp[1][i][j] = max(dp[1][i-1][j], dp[2][i-1][j-1]);
                dp[2][i][j] = max(dp[1][i-1][j-1], dp[2][i-1][j]) + 1;
            }
        }
    }
    
    int result = 0;
    
    for(int i=1; i<=d+1; i++) {
        if(i%2 == 1)
            result = max(result, dp[1][t][i]);
        
        else
            result = max(result, dp[2][t][i]);
    }
    
    cout << result;
    
    return 0;
}