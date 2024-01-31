#include <cstdio>
#include <queue>

using namespace std;

struct edge {
    int a, b;
    int cost;
    
    bool operator<(const edge e) const {
        return this->cost > e.cost;
    }
};
int v;
int parents[10001];
priority_queue<edge> edges;

int find_root(int n) {
    if(parents[n] == n)
        return n;
    parents[n] = find_root(parents[n]);
    return parents[n];
}

void union_root(int a, int b) {
    int ar = find_root(a);
    int br = find_root(b);
    
    if(ar != br)
        parents[br] = ar;
}

void find() {
    int result = 0;
    int count = 0;
    
    while(!edges.empty()) {
        edge e = edges.top();
        edges.pop();
        
        int a = e.a;
        int b = e.b;
        int cost = e.cost;
        
        if(find_root(a) != find_root(b)) {
            result += cost;
            count++;
            union_root(a, b);
        }
        
        if(count == (v-1))
            break;
    }
    
    printf("%d\n", result);
}

int main() {
    int e;
    
    scanf("%d%d", &v, &e);
    for(int i=1; i<=v; i++)
        parents[i] = i;
    
    for(int i=0; i<e; i++) {
        int a, b, c;
        
        scanf("%d%d%d", &a, &b, &c);
        
        edges.push({a, b, c});
    }
    
    find();
    
    return 0;
}