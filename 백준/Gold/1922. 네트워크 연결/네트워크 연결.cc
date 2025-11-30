#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
    int a;
    int b;
    int cost;
};

struct compare {
    bool operator()(edge a, edge b) {
        return a.cost > b.cost;
    }
};

int n, m;
int parent[1001];

bool check() {
    int c = parent[1];
    
    for(int i=2; i<=n; i++)
        if(parent[i] != c)
            return true;
    
    return false;
}

int main() {
    priority_queue<edge, vector<edge>, compare> pq;
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++)
        parent[i] = i;
    
    for(int i=0; i<m; i++) {
        edge e;
        
        cin >> e.a >> e.b >> e.cost;
        
        pq.push(e);
    }
    
    int result = 0;
    
    while(check()) {
        edge node = pq.top();
        pq.pop();
        
        if(parent[node.a] != parent[node.b]) {
            result += node.cost;
            
            int num = parent[node.b];
            
            for(int i=1; i<=n; i++)
                if(parent[i] == num)
                    parent[i] = parent[node.a];
        }
    }
    
    cout << result;
    
    return 0;
}