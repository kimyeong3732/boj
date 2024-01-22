#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
    int x;
    int y;
};

int result = 10000;
vector<point> h;
vector<point> c;
point chooseC[13];

void distance(int m) {
    int td = 0;

    for (int i = 0; i < h.size(); i++) {
        int d = 100;

        for (int j = 0; j < m; j++) {
            int cd = abs(h[i].x - chooseC[j].x) + abs(h[i].y - chooseC[j].y);

            if (d > cd)
                d = cd;
        }

        td += d;
    }

    if (result > td)
        result = td;
}

void choose(int a, int m, int count) {
    if (count == m) {
        distance(m);
        return;
    }

    for (int i = a; i < c.size(); i++) {
        chooseC[count] = c[i];
        choose(i + 1, m, count + 1);
    }
}

int main() {
    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            scanf("%d", &temp);

            if (temp == 1)
                h.push_back({ i, j });
            if (temp == 2)
                c.push_back({ i, j });
        }
    }

    choose(0, m, 0);

    printf("%d\n", result);

    return 0;
}