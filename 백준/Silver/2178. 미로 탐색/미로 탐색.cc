#include <cstdio>

struct point {
    int r;
    int c;
};

void BFS(int map[100][100], int n, int m, int br, int bc, point list[10000], int index, int size) {
    int r[4] = { 1, 0, -1, 0 };
    int c[4] = { 0, 1, 0, -1 };

    for (int i = 0; i < 4; i++) {
        point p;
        p.r = br + r[i];
        p.c = bc + c[i];
        if ((p.r >= 0) && (p.r < n) && (p.c >= 0) && (p.c < m)) {
            if (map[p.r][p.c] != 0) {
                if (map[p.r][p.c] == 10000) {
                    map[p.r][p.c] = map[br][bc] + 1;
                    list[size].r = p.r;
                    list[size].c = p.c;
                    size++;
                }
            }
        }
    }

    if (index < size) {
        BFS(map, n, m, list[index].r, list[index].c, list, index + 1, size);
    }
}

int main() {
    int n, m;
    int map[100][100];
    point list[10000];
    
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        char temp[101];
        scanf("%s", temp);
        for (int j = 0; j < m; j++) {
            map[i][j] = temp[j] - '0';
            if (map[i][j] == 1)
                map[i][j] += 9999;
        }
    }
    map[0][0] = 1;

    BFS(map, n, m, 0, 0, list, 0, 0);

    printf("%d\n", map[n - 1][m - 1]);

    return 0;
}