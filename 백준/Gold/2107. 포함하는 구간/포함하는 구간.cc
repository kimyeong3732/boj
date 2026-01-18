#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a, b;
        
        cin >> a >> b;
        
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(), v.end());
    
    int result = 0;
    
    for(int i=0; i<v.size()-1; i++) {
        int c = 0;
        int s = v[i].first;
        int e = v[i].second;
        
        for(int j=i+1; j<v.size(); j++) {
            if(v[j].first >= e-1)
                break;
            
            if(v[j].second < e)
                c++;
        }
        
        result = max(result, c);
    }
    
    cout << result;
    
    return 0;
}