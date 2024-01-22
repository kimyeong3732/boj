#include <cstdio>
#include <list>
using namespace std;

struct point {
    int x;
    int y;
    int distance;
};

int n, Stime = 0, Ssize = 2, Scount = 0;
list<point> l;

void BFS(int map[20][20], int visit[20][20], point shark) {
    if (l.empty())
        return;

    int x = l.front().x;
    int y = l.front().y;
    int distance = l.front().distance;
    l.pop_front();

    point sharktemp = shark;

    if ((!l.empty()) && ((l.front().x < x) || ((l.front().x == x) && (l.front().y < y))) && (l.front().distance == distance)) {
        point p;
        p.x = x;
        p.y = y;
        p.distance = distance;

        x = l.front().x;
        y = l.front().y;
        distance = l.front().distance;

        l.pop_front();
        l.push_front(p);
    }

    if ((map[x][y] != 0) && (map[x][y] < Ssize)) {
        map[shark.x][shark.y] = 0;
        map[x][y] = 9;
        Stime += distance;
        distance = 0;

        sharktemp.x = x;
        sharktemp.y = y;

        Scount++;
        if ((Scount == Ssize) && (Ssize < 7)) {
            Ssize++;
            Scount = 0;
        }

        while (!l.empty())
            l.pop_front();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (visit[i][j] == 1)
                    visit[i][j] = 0;
        
        visit[x][y] = 1;
    }

    int bx[] = { -1, 0, 0, 1 };
    int by[] = { 0, -1, 1, 0 };

    for (int i = 0; i < 4; i++) {
        int nx = x + bx[i];
        int ny = y + by[i];

        if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < n) && (map[nx][ny] <= Ssize) && (visit[nx][ny] == 0)) {
            point p;
            p.x = nx;
            p.y = ny;
            p.distance = distance + 1;
            
            visit[nx][ny] = 1;
            l.push_back(p);
        }
    }

    BFS(map, visit, sharktemp);
}

int main() {
    int map[20][20];
    int visit[20][20] = { 0 };

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9) {
                point p;
                p.x = i;
                p.y = j;
                p.distance = 0;
                
                visit[i][j] = 1;
                l.push_back(p);
            }
        }
    }

    BFS(map, visit, l.front());

    printf("%d\n", Stime);

    return 0;
}