#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int cost[10001];
vector<pair<int, int>> edges[10001];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    
    cost[s] = 0;
    
    pq.push(make_pair(0, s));
    
    while(!pq.empty()) {
        int node = pq.top().second;
        int t = pq.top().first;
        
        pq.pop();
        
        if(cost[node]>=0 && cost[node]<t)
            continue;
        
        for(int i=0; i<edges[node].size(); i++) {
            int next = edges[node][i].second;
            int nt = edges[node][i].first + t;
            
            if(cost[next]<0 || cost[next]>nt) {
                cost[next] = nt;
                
                pq.push(make_pair(nt, next));
            }
        }
    }
}

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int d, c;
        
        cin >> n >> d >> c;
        
        for(int j=1; j<=n; j++) {
            cost[j] = -1;
            edges[j].clear();
        }
        
        for(int j=0; j<d; j++) {
            int e, s, cc;
            
            cin >> e >> s >> cc;
            
            edges[s].push_back(make_pair(cc, e));
        }
        
        dijkstra(c);
        
        int rn=0, rm=0;
        
        for(int j=1; j<=n; j++) {
            if(cost[j] >= 0) {
                rn++;
                rm = max(rm, cost[j]);
            }
        }
        
        cout << rn << " " << rm << "\n";
    }
    
    return 0;
}