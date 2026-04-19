#include <iostream>

using namespace std;

int parent[100001];

int find(int x) {
    if(parent[x] == x)
        return x;
    
    return parent[x] = find(parent[x]);
}

void union_parent(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    
    if(pa > pb)
        parent[pa] = pb;
    
    else
        parent[pb] = pa;
}

int main() {
    int n, m;
    int result = 0;
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++)
        parent[i] = i;
    
    for(int i=0; i<m; i++) {
        int a, b;
        
        cin >> a >> b;
        
        if(find(a) == find(b)) {
            result++;
            continue;
        }
        
        union_parent(a, b);
    }
    
    for(int i=1; i<=n; i++)
        if(parent[i] == i)
            result++;
    
    result--;
    
    cout << result;
    
    return 0;
}