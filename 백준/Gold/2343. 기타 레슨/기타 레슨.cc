#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<int> v;
    
    cin >> n >> m;
    
    int l=0, r=0;
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        v.push_back(num);
        l = max(l, num);
        r += num;
    }
    
    while(l <= r) {
        int mid = (l + r) / 2;
        
        int c = 1;
        int s = 0;
        for(int i=0; i<n; i++) {
            if(s+v[i] > mid) {
                c++;
                s = 0;
            }
            
            s += v[i];
        }
        
        if(c <= m)
            r = mid - 1;
        
        else
            l = mid + 1;
    }
    
    cout << l;
    
    return 0;
}