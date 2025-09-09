#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long n;
    vector<long long> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        long long temp;
        
        cin >> temp;
        
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    long long result = 0;
    
    for(long long i=0; i<n; i++) {
        long long temp = v[i] - i - 1;
        
        if(temp < 0)
            temp *= -1;
        
        result += temp;
    }
    
    cout << result;
    
    return 0;
}