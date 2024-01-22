#include <cstdio>

int BFS(int n, int v, int nodes[100][100], int visit[100], int prelist[100], int presize, int list[100], int size, int index, int phase) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if ((nodes[v - 1][i] == 1) && (visit[i] == 0)) {
            visit[i] = 1;
            list[size] = i + 1;
            size++;
            count += phase;
        }
    }

    if(index < presize) {
        return count + BFS(n, prelist[index], nodes, visit, prelist, presize, list, size, index + 1, phase);
    }
    else {
        if (size > 0) {
            presize = 0;
            return count + BFS(n, list[0], nodes, visit, list, size, prelist, presize, 0, phase + 1);
        }
        else {
            return 0;
        }
    }
}

int main() {
    int n, m;
    int nodes[100][100] = { 0 };
    int list1[100];
    int list2[100];
    int min = 1000000, index;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int temp1, temp2;
        scanf("%d%d", &temp1, &temp2);
        nodes[temp1 - 1][temp2 - 1] = 1;
        nodes[temp2 - 1][temp1 - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        int visit[100] = { 0 };
        visit[i] = 1;
        int temp = BFS(n, i + 1, nodes, visit, list2, 0, list1, 0, 0, 1);

        if (min > temp) {
            index = i + 1;
            min = temp;
        }
    }

    printf("%d\n", index);

    return 0;
}