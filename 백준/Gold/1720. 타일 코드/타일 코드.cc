#include <iostream>

using namespace std;

int main() {
    int n;
    int dp[31];
    
    cin >> n;
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + 2 * dp[i-2];
    
    int pd = dp[n/2];
    
    if(n%2 == 0)
        pd += 2 * dp[n/2-1];
    
    cout << (dp[n] - pd) / 2 + pd;
    
    return 0;
}