#include <cstdio>

void DFS(int n, int v, int nodes[1000][1000], int visit[1000]) {
    for (int i = 0; i < n; i++) {
        if ((nodes[v - 1][i] == 1) && (visit[i] == 0)) {
            visit[i] = 1;
            printf(" %d", i + 1);
            DFS(n, i + 1, nodes, visit);
        }
    }
}

void BFS(int n, int v, int nodes[1000][1000], int visit[1000], int list[1000], int size, int index) {

    for (int i = 0; i < n; i++) {
        if ((nodes[v - 1][i] == 1) && (visit[i] == 0)) {
            visit[i] = 1;
            printf(" %d", i + 1);
            list[size] = i + 1;
            size++;
        }
    }

    if(index < size) {
        BFS(n, list[index], nodes, visit, list, size, index + 1);
    }
}

int main() {
    int n, m, v;
    int nodes[1000][1000] = { 0 };
    int visitD[1000] = { 0 };
    int visitB[1000] = { 0 };
    int list[1000];
    int size = 0, index = 0;

    scanf("%d%d%d", &n, &m, &v);

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        scanf("%d%d", &temp1, &temp2);
        nodes[temp1 - 1][temp2 - 1] = 1;
        nodes[temp2 - 1][temp1 - 1] = 1;
    }

    visitD[v - 1] = 1;
    printf("%d", v);
    DFS(n, v, nodes, visitD);
    printf("\n");

    visitB[v - 1] = 1;
    printf("%d", v);
    BFS(n, v, nodes, visitB, list, size, index);
    printf("\n");

    return 0;
}