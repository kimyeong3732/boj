#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visit[10];

int find(const vector<pair<int, int>> &v, int t) {
    int result = t;
    
    for(int i=0; i<v.size(); i++) {
        if(!visit[i] && t<=v[i].second) {
            visit[i] = true;
            result = max(result, find(v, t+v[i].first));
            visit[i] = false;
        }
    }
    
    return result;
}

int main() {
    int t;
    
    cin >> t;
    
    for(int i=1; i<=t; i++) {
        int n;
        vector<pair<int, int>> v;
        
        cin >> n;
        
        for(int j=0; j<n; j++) {
            int p, s;
            
            cin >> p >> s;
            
            v.push_back(make_pair(s, p));
        }
        
        sort(v.begin(), v.end());
        
        int result = find(v, 0);
        
        cout << "Case #" << i << ": " << result << "\n";
    }
    
    return 0;
}