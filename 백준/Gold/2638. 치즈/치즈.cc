#include <cstdio>
#include <queue>
using namespace std;

struct point {
    int x;
    int y;
};

int n, m;
int cheese[100][100];
int visit[100][100] = { 0 };
queue<point> q;

void fill() {
    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        cheese[x][y] = -1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m) && (visit[nx][ny]==0) && (cheese[nx][ny] == 0)) {
                visit[nx][ny] = 1;
                q.push({ nx, ny });
            }
        }
    }
}

void find() {
    int cnt = -1;

    q.push({ 0, 0 });
    visit[0][0] = 1;

    while (!q.empty()) {
        fill();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cheese[i][j] == 1) {
                    int cnt2 = 0;
                    if (cheese[i - 1][j] == -1)
                        cnt2++;
                    if (cheese[i + 1][j] == -1)
                        cnt2++;
                    if (cheese[i][j - 1] == -1)
                        cnt2++;
                    if (cheese[i][j + 1] == -1)
                        cnt2++;

                    if (cnt2 > 1) {
                        cheese[i][j] = 0;
                        q.push({ i, j });
                    }
                }
            }
        }

        cnt++;
    }

    printf("%d\n", cnt);
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &cheese[i][j]);

    find();

    return 0;
}