#include <iostream>

using namespace std;

int dp[1000001];

int main() {
    int n;
    
    dp[0] = 1;
    
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        if(i%2 == 1)
            dp[i] = dp[i-1];
        
        else
            dp[i] = dp[i-1] + dp[i/2];
        
        dp[i] %= 1000000000;
    }
    
    cout << dp[n];
    
    return 0;
}