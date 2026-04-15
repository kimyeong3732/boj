#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int cost[5001];
vector<pair<int, int>> edges[5001];

void dijkstra(int s) {
    for(int i=1; i<=n; i++) {
        if(i == s)
            cost[i] = 0;
        
        else
            cost[i] = 50000001;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push(make_pair(0, s));
    
    while(!pq.empty()) {
        int node = pq.top().second;
        int cc = pq.top().first;
        pq.pop();
        
        if(cost[node] < cc)
            continue;
        
        for(int i=0; i<edges[node].size(); i++) {
            int next = edges[node][i].second;
            int ccc = edges[node][i].first + cost[node];
            
            if(ccc < cost[next]) {
                cost[next] = ccc;
                pq.push(make_pair(ccc, next));
            }
        }
    }
}

int main() {
    int e, p;
    
    cin >> n >> e >> p;
    
    for(int i=0; i<e; i++) {
        int a, b, c;
        
        cin >> a >> b >> c;
        
        edges[a].push_back(make_pair(c, b));
        edges[b].push_back(make_pair(c, a));
    }
    
    dijkstra(1);
    
    int minc = cost[n];
    int minp = cost[p];
    
    dijkstra(p);
    
    if(minc == minp+cost[n])
        cout << "SAVE HIM";
    
    else
        cout << "GOOD BYE";
    
    return 0;
}