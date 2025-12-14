#include <iostream>

using namespace std;

long long dp[10001];

int main() {
    int n;
    
    cin >> n;
    
    dp[0] = 1;
    dp[2] = 1;
    
    for(int i=4; i<=n; i+=2) {
        for(int j=0; j<=i-2; j+=2) {
            dp[i] += dp[j] * dp[i-j-2];
            dp[i] %= 987654321;
        }
    }
    
    cout << dp[n];
    
    return 0;
}