#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int temp;
        
        cin >> temp;
        
        v.push_back(make_pair(temp, i));
    }
    
    sort(v.begin(), v.end());
    
    int result = 0;
    
    for(int i=0; i<n; i++) {
        int temp = v[i].second - i;
        
        if(temp > result)
            result = temp;
    }
    
    cout << result;
    
    return 0;
}