#include <iostream>

using namespace std;

long long dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(long long i=1; i<=1000000; i++) {
        for(long long j=i; j<=1000000; j+=i)
            dp[j] += i;
        
        dp[i] += dp[i-1];
    }
    
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int num;
        
        cin >> num;
        
        cout << dp[num] << "\n";
    }
    
    return 0;
}