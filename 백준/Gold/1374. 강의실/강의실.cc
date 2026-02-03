#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a, b, c;
        
        cin >> a >> b >> c;
        
        v.push_back(make_pair(b, c));
    }
    
    sort(v.begin(), v.end());
    
    pq.push(v[0].second);
    
    for(int i=1; i<n; i++) {
        if(pq.top() <= v[i].first)
            pq.pop();
        
        pq.push(v[i].second);
    }
    
    cout << pq.size();
    
    return 0;
}