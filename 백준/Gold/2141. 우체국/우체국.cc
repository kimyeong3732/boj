#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<pair<long long, long long>> v;
    long long sum = 0;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        long long x, a;
        
        cin >> x >> a;
        
        v.push_back(make_pair(x, a));
        
        sum += a;
    }
    
    sort(v.begin(), v.end());
    
    long long temp = 0;
    
    for(int i=0; i<n; i++) {
        temp += v[i].second;
        
        if(temp >= (sum+1)/2) {
            cout << v[i].first;
            break;
        }
    }
    
    return 0;
}