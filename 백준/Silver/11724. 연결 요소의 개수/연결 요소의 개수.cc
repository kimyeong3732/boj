#include <cstdio>

void DFS(int map[1000][1000], int visit[1000], int size, int a) {
    visit[a] = 1;
    for(int i=0; i<size; i++)
        if((map[a][i]==1) && (visit[i]==0))
            DFS(map, visit, size, i);
}

int find(int map[1000][1000], int visit[1000], int size) {
    int result = 0;
    for(int i=0; i<size; i++) {
        if(visit[i] == 0) {
            DFS(map, visit, size, i);
            result++;
        }
    }
    
    return result;
}

int main() {
    int n, m;
    int map[1000][1000] = {0};
    int visit[1000] = {0};
    
    scanf("%d%d", &n, &m);
    
    for(int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        
        map[a-1][b-1] = 1;
        map[b-1][a-1] = 1;
    }
    
    printf("%d\n", find(map, visit, n));
    
    return 0;
}