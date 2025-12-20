#include <iostream>

using namespace std;

int parent[1000001];

int find(int node) {
    if(node == parent[node])
        return node;
    
    return parent[node] = find(parent[node]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    
    cin >> n >> m;
    
    for(int i=0; i<=n; i++)
        parent[i] = i;
    
    for(int i=0; i<m; i++) {
        int order, a, b;
        
        cin >> order >> a >> b;
        
        int ap = find(a);
        int bp = find(b);
        
        if(order == 0) {
            parent[bp] = ap;
        }
        
        else {
            if(ap == bp)
                cout << "YES\n";
            
            else
                cout << "NO\n";
        }
    }
    
    return 0;
}