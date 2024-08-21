#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point {
    int to;
    int cost;
};

int n, m;

int edges[500][500];

int dijstra(int start, int end) {
    int costs[500];
    vector<int> from[500];
    bool visited[500];
    
    for(int i=0; i<n; i++) {
        costs[i] = -1;
        visited[i] = false;
        
        if(i == start) {
            costs[i] = 0;
        }
    }
    
    int node = start;
    
    while(node != end) {
        visited[node] = true;
        
        for(int i=0; i<n; i++) {
            if(i==node || edges[node][i]==0 || visited[i]) {
                continue;
            }
            
            if(costs[i]<0 || costs[node]+edges[node][i]<=costs[i]) {
                if(costs[i]<0 || costs[node]+edges[node][i]<costs[i]) {
                    from[i].resize(0);
                    
                    costs[i] = costs[node] + edges[node][i];
                }
                
                from[i].push_back(node);
            }
        }
        
        int cost = 500000;
        
        for(int i=0; i<n; i++) {
            if(visited[i]) {
                continue;
            }
            
            if(costs[i]>0 && costs[i]<cost) {
                cost = costs[i];
                node = i;
            }
        }
        
        if(visited[node]) {
            break;
        }
    }
    
    bool f_visited[500];
    
    for(int i=0; i<n; i++) {
        f_visited[i] = false;
    }
    
    queue<int> froms;
    
    f_visited[node] = true;
    froms.push(node);
    
    while(!froms.empty()) {
        node = froms.front();
        froms.pop();
        
        for(int i=0; i<from[node].size(); i++) {
            edges[from[node][i]][node] = 0;
            
            if(f_visited[from[node][i]]) {
                continue;
            }
            
            froms.push(from[node][i]);
            f_visited[from[node][i]] = true;
        }
    }
    
    return costs[end];
}

int main() {
    cin >> n >> m;
    
    while(n+m != 0) {
        int s, e;
        
        cin >> s >> e;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                edges[i][j] = 0;
            }
        }
    
        for(int i=0; i<m; i++) {
            int a, b, c;
            
            cin >> a >> b >> c;
            edges[a][b] = c;
        }
        
        dijstra(s, e);
        
        int result = dijstra(s, e);
        
        cout << result << "\n";
        
        cin >> n >> m;
    }
    
    return 0;
}