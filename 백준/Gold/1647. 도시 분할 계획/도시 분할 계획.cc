#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct edge {
    int a, b, cost;
};

struct compare {
    bool operator()(edge a, edge b) {
        return a.cost > b.cost;
    }
};

int n, m;
int parent[100001];

int find_parent(int node) {
    if(node == parent[node])
        return node;
    
    return parent[node] = find_parent(parent[node]);
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
    int count = 0;
    
    while(true) {
        if(count == n-2)
            break;
        
        edge node = pq.top();
        pq.pop();
        
        int pa = find_parent(node.a);
        int pb = find_parent(node.b);
        
        if(pa != pb) {
            parent[pb] = pa;
            
            result += node.cost;
            count++;
        }
    }
    
    cout << result;
    
    return 0;
}