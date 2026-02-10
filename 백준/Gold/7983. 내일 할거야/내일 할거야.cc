#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int b, t;
        
        cin >> b >> t;
        
        v.push_back(make_pair(t, b));
    }
    
    sort(v.begin(), v.end());
    
    int result = v[n-1].first;
    
    for(int i=n-1; i>=0; i--) {
        if(v[i].first < result)
            result = v[i].first;
        
        result -= v[i].second;
    }
    
    cout << result;
    
    return 0;
}