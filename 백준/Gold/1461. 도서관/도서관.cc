#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<int> plus, minus;
    vector<int> v;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        int temp;
        
        cin >> temp;
        
        if(temp > 0)
            plus.push_back(temp);
        
        else
            minus.push_back(-temp);
    }
    
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end(), greater<int>());
    
    int c = 0;
    
    for(int i=0; i<plus.size(); i++) {
        c++;
        
        if(c == 1)
            v.push_back(plus[i]);
        
        if(c==m || i==plus.size()-1)
            c = 0;
    }
    
    c = 0;
    
    for(int i=0; i<minus.size(); i++) {
        c++;
        
        if(c == 1)
            v.push_back(minus[i]);
        
        if(c==m || i==minus.size()-1)
            c = 0;
    }
    
    sort(v.begin(), v.end());
    
    int r = 0;
    
    for(int i=0; i<v.size(); i++) {
        if(i < v.size()-1)
            r += v[i];
        
        r += v[i];
    }
    
    cout << r;
    
    return 0;
}