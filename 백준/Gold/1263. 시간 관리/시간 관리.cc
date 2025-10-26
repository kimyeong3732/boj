#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    priority_queue<pair<int, int>> pq;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int c, s;
        
        cin >> c >> s;
        
        pq.push(make_pair(s, c));
    }
    
    int t = 1000000;
    
    while(t>0 && !pq.empty()) {
        if(t > pq.top().first)
            t = pq.top().first;
        
        t -= pq.top().second;
        
        pq.pop();
    }
    
    if(t < 0)
        t = -1;
    
    cout << t;
    
    return 0;
}