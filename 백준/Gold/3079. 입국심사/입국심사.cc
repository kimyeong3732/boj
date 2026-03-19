#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long n, m;
    vector<long long> v;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        long long num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    long long l=1, r=m*v[n-1];
    long long result = r;
    
    while(l <= r) {
        long long mid = (l + r) / 2;
        long long temp = 0;
        
        for(int i=0; i<n; i++) {
            temp += mid / v[i];
            
            if(temp >= m)
                break;
        }
        
        if(temp >= m) {
            if(result > mid)
                result = mid;
            
            r = mid - 1;
        }
        
        else {
            l = mid + 1;
        }
    }
    
    cout << result;
    
    return 0;
}