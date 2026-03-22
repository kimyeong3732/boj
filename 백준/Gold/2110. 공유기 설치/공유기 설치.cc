#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    vector<int> v;
    
    cin >> n >> d;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    int l=1, r=v[n-1]-v[0];
    int result = 0;
    
    while(l <= r) {
        int mid = (l + r) / 2;
        
        int c = 1;
        int pre = v[0];
        
        for(int i=1; i<n; i++) {
            if(v[i]-pre >= mid) {
                c++;
                
                pre = v[i];
            }
            
            if(c >= d)
                break;
        }
        
        if(c >= d) {
            result = max(result, mid);
            
            l = mid + 1;
        }
        
        else {
            r = mid - 1;
        }
    }
    
    cout << result;
    
    return 0;
}