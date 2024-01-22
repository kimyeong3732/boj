#include <cstdio>

struct point {
    int x;
    int y;
};

int BFS(int map[1000][1000], int m, int n, point list[1000000], int index, int size) {
    if ((index == size))
        return 0;

    int resultsize = size;
    int bx[] = { -1, 1, 0, 0 };
    int by[] = { 0, 0, -1, 1 };

    for (int i = index; i < size; i++) {
        int x = list[i].x;
        int y = list[i].y;
        
        for (int j = 0; j < 4; j++) {
            int ax = x + bx[j];
            int ay = y + by[j];

            if ((ax >= 0) && (ax < n) && (ay >= 0) && (ay < m)) {
                if (map[ax][ay] == 0) {
                    map[ax][ay] = 1;
                    list[resultsize].x = ax;
                    list[resultsize].y = ay;
                    resultsize++;
                }
            }
        }
    }

    return 1 + BFS(map, m, n, list, size, resultsize);

}

int main() {
    int m, n;
    int map[1000][1000];
    point list[1000000];
    int size = 0;

    scanf("%d%d", &m, &n);

    for (int i = 0; i <n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) {
                list[size].x = i;
                list[size].y = j;
                size++;
            }
        }
    }

    int result = BFS(map, m, n, list, 0, size);
    int state = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == 0)
                state = 1;

    if (state == 1)
        printf("-1\n");

    else
        printf("%d\n", result - 1);

    return 0;

}