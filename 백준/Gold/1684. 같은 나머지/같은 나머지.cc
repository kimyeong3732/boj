#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

int main() {
    int n;
    vector<int> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<n-1; i++)
        v[i] = v[i+1] - v[i];
    
    int r = v[0];
    
    for(int i=1; i<n-1; i++)
        r = gcd(r, v[i]);
    
    cout << r;
    
    return 0;
}