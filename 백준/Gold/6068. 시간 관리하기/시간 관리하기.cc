#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    
    int l = 1000000;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a, b;
        
        cin >> a >> b;
        
        v.push_back(make_pair(b, a));
    }
    
    sort(v.begin(), v.end());
    
    for(int i=v.size()-1; i>=0; i--) {
        l = min(l, v[i].first);
        
        l -= v[i].second;
        
        if(l < 0) {
            l = -1;
            break;
        }
    }
    
    cout << l;
    
    return 0;
}