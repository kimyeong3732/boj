#include <iostream>

using namespace std;

int main() {
    int n;
    int dp[1000001];
    
    dp[0] = 0;
    
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        int h = 6;
        int c = 2;
        
        dp[i] = dp[i-1] + 1;
        
        while(i >= h) {
            if(dp[i] > dp[i-h]+1)
                dp[i] = dp[i-h] + 1;
            
            h += c * 3;
            c++;
            h += c;
        }
    }
    
    cout << dp[n];
    
    return 0;
}