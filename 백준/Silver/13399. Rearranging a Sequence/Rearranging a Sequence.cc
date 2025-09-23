#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<pair<int, int>> v;
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++)
        v.push_back(make_pair(n-i, i));
    
    for(int i=0; i<m; i++) {
        int num;
        
        cin >> num;
        
        v[num-1].first = n;
        
        n++;
    }
    
    sort(v.begin(), v.end(), greater<>());
    
    for(int i=0; i<v.size(); i++)
        cout << v[i].second << "\n";
    
    return 0;
}