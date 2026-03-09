#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a, b;
        
        cin >> a >> b;
        
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(), v.end());
    
    int result = 0;
    
    for(int i=0; i<n; i++) {
        if(!pq.empty() && pq.top()<=v[i].first)
            pq.pop();
        
        pq.push(v[i].second);
        
        result = max(result, (int)pq.size());
    }
    
    cout << result;
    
    return 0;
}