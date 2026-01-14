#include <iostream>
#include <algorithm>

using namespace std;

int coin[100];
int dp[10001];

int main() {
    int n, k;
    
    cin >> n >> k;
    
    for(int i=0; i<n; i++)
        cin >> coin[i];
    
    sort(coin, coin+n);
    
    for(int i=0; i<n; i++) {
        if(coin[i] > k)
            break;
        
        int num = coin[i];
        
        dp[num] = 1;
        
        for(int j=num+1; j<=k; j++) {
            if(dp[j-num] == 0)
                continue;
            
            if(dp[j] == 0) {
                dp[j] = dp[j-num] + 1;
                continue;
            }
            
            dp[j] = min(dp[j], dp[j-num]+1);
        }
    }
    
    if(dp[k] == 0)
        dp[k] = -1;
    
    cout << dp[k];
    
    return 0;
}