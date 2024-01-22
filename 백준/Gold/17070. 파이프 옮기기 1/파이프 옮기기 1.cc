#include <cstdio>

struct point {
    int x;
    int y;
};

int maps[16][16];
int result = 0;

void DFS(int n, point a, point b) {
    int ax = a.x, ay = a.y;
    int bx = b.x, by = b.y;

    if ((bx == (n - 1)) && (by == (n - 1))) {
        result++;
        return;
    }

    if ((ay != by) && (by < (n - 1)) && (maps[bx][by + 1] != 1))
        DFS(n, b, { bx, by + 1 });

    if ((bx < (n - 1)) && (by < (n - 1)) && (maps[bx][by + 1] != 1) && (maps[bx + 1][by] != 1) && (maps[bx + 1][by + 1] != 1))
        DFS(n, b, { bx + 1, by + 1 });

    if ((ax != bx) && (bx < (n - 1)) && (maps[bx + 1][by] != 1))
        DFS(n, b, { bx + 1, by });
}

int main() {
    int n;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &maps[i][j]);

    maps[0][0] = 1;
    maps[0][1] = 1;

    DFS(n, { 0, 0 }, { 0, 1 });

    printf("%d\n", result);

    return 0;
}