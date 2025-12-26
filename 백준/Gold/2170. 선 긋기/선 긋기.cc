#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    vector<pair<int, int>> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a, b;
        
        cin >> a >> b;
        
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(), v.end());
    
    int result = 0;
    
    int s = v[0].first;
    int e = v[0].second;
    
    for(int i=1; i<v.size(); i++) {
        if(e < v[i].first) {
            result += e - s;
            s = v[i].first;
        }
        
        e = max(e, v[i].second);
    }
    
    result += e - s;
    
    cout << result;
    
    return 0;
}