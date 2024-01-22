#include <cstdio>

int n, m;
int result = 0;

void DFS(int map[500][500], int visit[500][500], int x, int y, int count, int num) {
    int resultnum = num + map[x][y];

    if (count == 3) {
        if (result < resultnum)
            result = resultnum;
        return;
    }

    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    visit[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ((nx < n) && (nx >= 0) && (ny < m) && (ny >= 0) && (visit[nx][ny] == 0))
            DFS(map, visit, nx, ny, count + 1, resultnum);
    }

    visit[x][y] = 0;
}

void another(int map[500][500], int x, int y, int order) {
    int resultnum = 0;
    switch (order) {
    case 0:
        if ((x < (n - 2)) && (y > 0))
            resultnum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y - 1];
        break;
    case 1:
        if ((x < (n - 2)) && (y < (m - 1)))
            resultnum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
        break;
    case 2:
        if ((x > 0) && (y < (m - 2)))
            resultnum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1];
        break;
    case 3:
        if ((x < (n - 1)) && (y < (m - 2)))
            resultnum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1];
        break;
    default:
        break;
    }

    if (result < resultnum)
        result = resultnum;
}

int main() {
    int map[500][500];
    int visit[500][500] = { 0 };

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            DFS(map, visit, i, j, 0, 0);
            for (int k = 0; k < 4; k++)
                another(map, i, j, k);
        }
    }

    printf("%d\n", result);

    return 0;
}