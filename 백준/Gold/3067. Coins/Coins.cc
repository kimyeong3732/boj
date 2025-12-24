#include <iostream>

using namespace std;

int dp[21][10001];

int main() {
    int t;
    
    for(int i=0; i<=20; i++)
        dp[i][0] = 1;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int n;
        int coin[20];
        int dest;
        
        cin >> n;
        
        for(int j=1; j<=n; j++)
            cin >> coin[j];
        
        cin >> dest;
        
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=dest; k++) {
                dp[j][k] = dp[j-1][k];
                
                if(coin[j] <= k)
                    dp[j][k] += dp[j][k-coin[j]];
            }
        }
        
        cout << dp[n][dest] << "\n";
    }
    
    return 0;
}