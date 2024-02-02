#include <cstdio>
#include <queue>

using namespace std;

int has_parent[32001];
queue<int> childs[32001];
queue<int> nodes;

void find() {
    while(!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();
        printf("%d ", node);
        
        while(!childs[node].empty()) {
            int child = childs[node].front();
            childs[node].pop();
            
            if(--has_parent[child] == 0)
                nodes.push(child);
        }
    }
    
    printf("\n");
}

int main() {
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    for(int i=0; i<m; i++) {
        int a, b;
        
        scanf("%d%d", &a, &b);
        
        has_parent[b]++;
        childs[a].push(b);
    }
    
    for(int i=1; i<=n; i++)
        if(has_parent[i] == 0)
            nodes.push(i);
            
    find();
    
    return 0;
}