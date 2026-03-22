#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, l;
    vector<int> v;
    
    cin >> n >> m >> l;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    v.push_back(0);
    v.push_back(l);
    
    sort(v.begin(), v.end());
    
    int s=1, e=l-1;
    int result = 999;
    
    while(s <= e) {
        int mid = (s + e) / 2;
        
        int c = 0;
        
        for(int i=1; i<v.size(); i++) {
            int temp = v[i] - v[i-1];
            
            int ct = temp / mid;
            
            if(ct > 0) {
                c += ct;
                
                if(temp%mid == 0)
                    c--;
            }
        }
        
        if(c > m)
            s = mid + 1;
        
        else {
            e = mid - 1;
            
            result = min(mid, result);
        }
    }
    
    cout << result;
    
    return 0;
}