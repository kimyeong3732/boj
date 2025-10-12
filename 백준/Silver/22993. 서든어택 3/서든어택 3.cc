#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    int i;
    long long s;
    vector<long long> v;
    
    cin >> n >> s;
    
    for(i=0; i<n-1; i++) {
        long long num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    for(i=0; i<n-1; i++) {
        if(s <= v[i])
            break;
        
        else
            s += v[i];
    }
    
    if(i < n-1)
        cout << "No";
    
    else
        cout << "Yes";
    
    return 0;
}