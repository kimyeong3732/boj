#include <iostream>

using namespace std;

int dp[100001];

int main() {
    int d, p;
    
    cin >> d >> p;
    
    dp[0] = 8388608;
    
    for(int i=0; i<p; i++) {
        int a, b;
        
        cin >> a >> b;
        
        for(int j=d; j>=a; j--)
            dp[j] = max(dp[j], min(dp[j-a], b));
    }
    
    cout << dp[d];
    
    return 0;
}