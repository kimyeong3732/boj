#include <iostream>
#include <vector>

using namespace std;

int n, e;
vector<int> edge[20001];
int visit[20001];

void dfs(int node, int num) {
    visit[node] = num;
    
    for(int i=0; i<edge[node].size(); i++) {
        int next = edge[node][i];
        
        if(visit[next] == 0)
            dfs(next, -num);
    }
}

bool check() {
    for(int i=1; i<=n; i++) {
        for(int j=0; j<edge[i].size(); j++) {
            int next = edge[i][j];
            
            if(visit[i] == visit[next])
                return false;
        }
    }
    
    return true;
}

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        cin >> n >> e;
        
        for(int j=0; j<e; j++) {
            int a, b;
            
            cin >> a >> b;
            
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        
        for(int j=1; j<=n; j++)
            if(visit[j] == 0)
                dfs(j, 1);
        
        if(check())
            cout << "YES\n";
        else
            cout << "NO\n";
        
        for(int j=1; j<=n; j++) {
            edge[j].clear();
            visit[j] = 0;
        }
    }
    
    return 0;
}