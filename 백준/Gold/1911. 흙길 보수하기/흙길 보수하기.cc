#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    vector<pair<int, int>> v;
    
    cin >> n >> l;
    
    for(int i=0; i<n; i++) {
        int a, b;
        
        cin >> a >> b;
        
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(), v.end());
    
    int result = 0;
    int c = 0;
    
    for(int i=0; i<n; i++) {
        int f = v[i].first;
        int e = v[i].second;
        int ct;
        
        if(c >= e)
            continue;
        
        if(f > c)
            c = f;
        
        ct = (e - c) / l;
        
        if((e-c)%l != 0)
            ct++;
        
        c += ct * l;
        
        result += ct;
    }
    
    cout << result;
    
    return 0;
}