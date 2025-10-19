#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long n;
    vector<long long> v;
    
    cin >> n;
    
    for(long long i=0; i<n; i++) {
        long long num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end(), greater<>());
    
    long long r = 0;
    
    for(long long i=0; i<n; i++)
        if(v[i]-i > 0)
            r += v[i] - i;
    
    cout << r;
    
    return 0;
}