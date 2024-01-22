#include <cstdio>

int countVirus = 0;

void BFS(int n, int v, int nodes[100][100], int virus[100], int list[100], int size, int index) {

    for (int i = 0; i < n; i++) {
        if ((nodes[v - 1][i] == 1) && (virus[i] == 0)) {
            virus[i] = 1;
            countVirus++;
            list[size] = i + 1;
            size++;
        }
    }

    if (index < size) {
        BFS(n, list[index], nodes, virus, list, size, index + 1);
    }
}

int main() {
    int n, m;
    int nodes[100][100] = { 0 };
    int virus[100] = { 0 };
    int list[100];
    int size = 0, index = 0;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        scanf("%d%d", &temp1, &temp2);
        nodes[temp1 - 1][temp2 - 1] = 1;
        nodes[temp2 - 1][temp1 - 1] = 1;
    }

    virus[0] = 1;
    BFS(n, 1, nodes, virus, list, size, index);
    printf("%d\n", countVirus);

    return 0;
}