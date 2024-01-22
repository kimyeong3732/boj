#include <cstdio>
#include <queue>
using namespace std;

struct point {
    int x;
    int y;
    int wall;
};

int n, m, state = 0;
char mymap[1000][1001];
int visit[1000][1000][2] = { 0 };
int result[1000][1000] = { 0 };

queue<point> q;

void find() {
    int bx[] = { -1, 1, 0, 0 };
    int by[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int wall = q.front().wall;
        q.pop();

        if ((x == n - 1) && (y == m - 1)) {
            state = 1;
            printf("%d\n", result[x][y]);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + bx[i];
            int ny = y + by[i];

            if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m)) {
                if ((mymap[nx][ny] == '1') && (wall == 0) && (visit[nx][ny][wall + 1] == 0)) {
                    visit[nx][ny][wall + 1] = 1;
                    result[nx][ny] = result[x][y] + 1;
                    q.push({ nx, ny, wall + 1 });
                }

                if ((mymap[nx][ny] == '0') && (visit[nx][ny][wall] == 0)) {
                    visit[nx][ny][wall] = 1;
                    result[nx][ny] = result[x][y] + 1;
                    q.push({ nx, ny, wall });
                }
            }
        }
    }
}

int main() {

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%s", mymap[i]);

    q.push({ 0, 0, 0 });
    result[0][0] = 1;

    find();

    if (state == 0)
        printf("-1\n");

    return 0;
}