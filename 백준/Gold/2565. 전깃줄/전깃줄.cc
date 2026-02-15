#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    vector<int> dp;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a, b;
        
        cin >> a >> b;
        
        v.push_back(make_pair(a, b));
        dp.push_back(1);
    }
    
    sort(v.begin(), v.end());
    
    int result = 1;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++)
            if(v[j].second < v[i].second)
                dp[i] = max(dp[i], dp[j]+1);
        
        result = max(result, dp[i]);
    }
    
    cout << n-result;
    
    return 0;
}