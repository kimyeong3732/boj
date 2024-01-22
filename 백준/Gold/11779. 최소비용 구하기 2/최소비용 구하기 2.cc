#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct point {
    int dest;
    int cost;
};

vector<point> p[1000];
int cw[1000];
int r[1000];

void find(int start) {
    queue<point> q;

    q.push({ start, 0 });
    cw[start] = 0;

    while (!q.empty()) {
        int num = q.front().dest;
        int ct = q.front().cost;
        q.pop();

        if (ct > cw[num])
            continue;

        for (int i = 0; i < p[num].size(); i++) {
            int d = p[num][i].dest;
            int c = p[num][i].cost;

            if (cw[d] <= (ct + c))
                continue;

            r[d] = num;

            cw[d] = ct + c;
            q.push({ d, cw[d] });
        }
    }
}

int main() {
    int n, m;
    int start, end;
    vector<int> rt;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, c;

        scanf("%d%d%d", &a, &b, &c);

        p[a - 1].push_back({ b - 1, c });
    }

    for (int i = 0; i < n; i++)
        cw[i] = 100000001;
    
    scanf("%d%d", &start, &end);

    find(start - 1);

    printf("%d\n", cw[end - 1]);

    end--;
    while (end != (start - 1)) {
        rt.push_back(end + 1);

        end = r[end];
    }
    printf("%d\n%d ", rt.size() + 1, start);

    for (int i = rt.size() - 1; i >= 0; i--)
        printf("%d ", rt[i]);
    printf("\n");

    return 0;
}