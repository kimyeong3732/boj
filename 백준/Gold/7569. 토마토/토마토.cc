#include <cstdio>

struct point {
    int x;
    int y;
    int z;
};

int BFS(int map[100][100][100], int m, int n, int h, point list[1000000], int index, int size) {
    if ((index == size))
        return 0;

    int resultsize = size;
    int bx[] = { -1, 1, 0, 0, 0, 0 };
    int by[] = { 0, 0, -1, 1, 0, 0 };
    int bz[] = { 0, 0, 0, 0, -1, 1 };

    for (int i = index; i < size; i++) {
        int x = list[i].x;
        int y = list[i].y;
        int z = list[i].z;

        for (int j = 0; j < 6; j++) {
            int ax = x + bx[j];
            int ay = y + by[j];
            int az = z + bz[j];
            if ((ax >= 0) && (ax < h) && (ay >= 0) && (ay < n) && (az >= 0) && (az < m)) {
                if (map[ax][ay][az] == 0) {
                    map[ax][ay][az] = 1;
                    list[resultsize].x = ax;
                    list[resultsize].y = ay;
                    list[resultsize].z = az;
                    resultsize++;
                }
            }
        }
    }

    return 1 + BFS(map, m, n, h, list, size, resultsize);
}

int main() {
    int m, n, h;
    int map[100][100][100];
    point list[1000000];
    int size = 0;
    
    scanf("%d%d%d", &m, &n, &h);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &map[i][j][k]);
                if (map[i][j][k] == 1) {
                    list[size].x = i;
                    list[size].y = j;
                    list[size].z = k;
                    size++;
                }
            }
        }
    }

    int result = BFS(map, m, n, h, list, 0, size);
    int state = 0;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                if (map[i][j][k] == 0)
                    state = 1;

    if (state == 1)
        printf("-1\n");

    else
        printf("%d\n", result - 1);

    return 0;
}