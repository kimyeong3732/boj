#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    vector<int> v;
    int total = 1;
    int diff = 1;
    int count = 1;
    
    while(total <= n) {
        v.push_back(total);
        
        count++;
        diff += count;
        total += diff;
    }
    
    vector<int> dp;
    
    dp.push_back(0);
    
    for(int i=1; i<=n; i++) {
        dp.push_back(dp[i-1]+1);
        
        for(int j=1; j<v.size(); j++) {
            if(v[j] > i)
                break;
            
            int temp = dp[i-v[j]] + 1;
            
            if(dp[i] > temp)
                dp[i] = temp;
        }
    }
    
    cout << dp[n];
    
    return 0;
}