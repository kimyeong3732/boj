#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<int> v;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    int result = 2000000000;
    
    int l=0, r=0;
    
    while(r < v.size()) {
        int d = v[r] - v[l];
        
        if(d < m) {
            r++;
        }
        
        else {
            if(d != 0)
                l++;
            
            else
                r++;
            
            result = min(result, d);
        }
    }
    
    cout << result;
    
    return 0;
}