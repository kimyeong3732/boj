#include <iostream>

using namespace std;

long long dp[10][2001];

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int n, m;
        
        cin >> n >> m;
        
        for(int j=0; j<n; j++) {
            for(int k=1; k<=m; k++) {
                if(j == 0)
                    dp[j][k] = 1;
                
                else
                    dp[j][k] = 0;
            }
        }
        
        for(int j=0; j<n-1; j++)
            for(int k=1; k<=m; k++)
                for(int l=k*2; l<=m; l++)
                    dp[j+1][l] += dp[j][k];
        
        long long result = 0;
        
        for(int j=1; j<=m; j++)
            result += dp[n-1][j];
        
        cout << result << "\n";
    }
    
    return 0;
}