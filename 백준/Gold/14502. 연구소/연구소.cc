#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct point {
    int x;
    int y;
};

int arr[8][8];

int BFS(int n, int m) {
    int safe = 0;
    int bx[] = { -1, 1, 0, 0 };
    int by[] = { 0, 0, -1, 1 };
    int copyarr[8][8];
    int visit[8][8] = { 0 };
    queue<point> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            copyarr[i][j] = arr[i][j];

            if (arr[i][j] == 2) {
                visit[i][j] = 1;
                q.push({ i, j });
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + bx[i];
            int ny = y + by[i];

            if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m) && (copyarr[nx][ny] == 0) && (visit[nx][ny] == 0)) {
                visit[nx][ny] = 1;
                copyarr[nx][ny] = 2;
                q.push({ nx, ny });
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (copyarr[i][j] == 0)
                safe++;

    return safe;
}

void find(int n, int m) {
    int maxsafe = 0;
    vector<point> v;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 0)
                v.push_back({ i, j });

    for (int i = 0; i < (v.size() - 2); i++) {
        if (arr[v[i].x][v[i].y] == 0) {
            arr[v[i].x][v[i].y] = 1;

            for (int j = i + 1; j < (v.size() - 1); j++) {
                if (arr[v[j].x][v[j].y] == 0) {
                    arr[v[j].x][v[j].y] = 1;

                    for (int k = j + 1; k < v.size(); k++) {
                        if(arr[v[k].x][v[k].y] == 0) {
                            arr[v[k].x][v[k].y] = 1;

                            maxsafe = max(maxsafe, BFS(n, m));

                            arr[v[k].x][v[k].y] = 0;
                        }
                    }

                    arr[v[j].x][v[j].y] = 0;
                }
            }

            arr[v[i].x][v[i].y] = 0;
        }
    }

    printf("%d\n", maxsafe);
}

int main() {
    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);

    find(n, m);

    return 0;
}