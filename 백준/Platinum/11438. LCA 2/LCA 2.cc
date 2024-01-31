#include <cstdio>
#include <vector>
using namespace std;

vector<int> edges[100001];
int parents[100001][18];
int deep[100001];

void tree(int n, int p, int d) {
    parents[n][0] = p;
    deep[n] = d + 1;
    
    int node = p;
    
    for(int i=0; parents[node][i]!=0; i++) {
        parents[n][i+1] = parents[node][i];
        node = parents[node][i];
    }
    
    for(int i=0; i<edges[n].size(); i++)
        if(deep[edges[n][i]] == 0)
            tree(edges[n][i], n, d+1);
}

void find(int a, int b) {
    int big = a;
    int small = b;
    
    if(deep[a] < deep[b]) {
        big = b;
        small = a;
    }
    
    if(big != small) {
        for(int i=17; i>=0; i--) {
            if(deep[parents[big][i]] >= deep[small]) {
                big = parents[big][i];
            }
        }
    }
    
    int result = big;
    if(big != small) {
        for(int i=17; i>=0; i--) {
            if(parents[big][i] != parents[small][i]) {
                big = parents[big][i];
                small = parents[small][i];
            }
            result = parents[big][i];
        }
    }
    
    printf("%d\n", result);
}

int main() {
    int n, m;
    
    scanf("%d", &n);
    
    for(int i=0; i<n-1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    tree(1, 0, 0);
    
    scanf("%d", &m);
    
    for(int i=0; i<m; i++) {
        int a, b;
        
        scanf("%d%d", &a, &b);
        
        find(a, b);
    }
    
    return 0;
}