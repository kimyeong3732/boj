#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<long long> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        long long num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    long long result = 0;
    
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            long long c = v[i] + v[j];
            
            long long s = lower_bound(v.begin()+j+1, v.end(), -c) - v.begin();
            long long e = upper_bound(v.begin()+j+1, v.end(), -c) - v.begin();
            
            result += e - s;
        }
    }
    
    cout << result;
    
    return 0;
}