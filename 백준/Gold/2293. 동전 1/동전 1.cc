#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];

int main() {
    int n, k;
    vector<int> v;
    
    cin >> n >> k;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++) {
        int coin = v[i];
        
        if(coin > k)
            break;
        
        dp[coin]++;
        
        for(int j=1; j<=k-coin; j++)
            if(dp[j]>0 && j+coin<=k)
                dp[j+coin] += dp[j];
    }
    
    cout << dp[k];
    
    return 0;
}