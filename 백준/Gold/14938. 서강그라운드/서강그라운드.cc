#include <cstdio>
#include <algorithm>
using namespace std;

int item[100];
int way[100][100];

void floid(int n, int m) {
    int result = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                way[j][k] = min(way[j][k], way[j][i] + way[i][k]);

    for (int i = 0; i < n; i++) {
        int temp = 0;

        for (int j = 0; j < n; j++)
            if (way[i][j] <= m)
                temp += item[j];

        result = max(result, temp);
    }

    printf("%d\n", result);
}

int main() {
    int n, m, r;

    scanf("%d%d%d", &n, &m, &r);

    for (int i = 0; i < n; i++)
        scanf("%d", &item[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                way[i][j] = 0;
            else
                way[i][j] = 1501;
        }
    }

    for (int i = 0; i < r; i++) {
        int node1, node2, l;

        scanf("%d%d%d", &node1, &node2, &l);

        way[node1 - 1][node2 - 1] = l;
        way[node2 - 1][node1 - 1] = l;
    }

    floid(n, m);

    return 0;
}