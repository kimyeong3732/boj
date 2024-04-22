#include <iostream>
#include <queue>

using namespace std;

int counts[32001];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v[32001];

void topology() {
    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();
        
        cout << node << ' ';
        
        for(int i=0; i<v[node].size(); i++) {
            counts[v[node][i]]--;
            
            if(counts[v[node][i]] == 0)
                pq.push(v[node][i]);
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    
    cin >> n >> m;
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        counts[b]++;
        v[a].push_back(b);
    }
    
    for(int i=1; i<=n; i++)
        if(counts[i] == 0)
            pq.push(i);
    
    topology();
    
    return 0;
}