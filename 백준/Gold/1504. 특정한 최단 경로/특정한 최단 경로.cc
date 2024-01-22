#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct line {
    int node;
    int cost;
};

struct cmp {
    bool operator()(const line& a, const line& b) {
        if (a.cost == b.cost)
            return a.node > b.node;
        return a.cost > b.cost;
    }
};

vector<line> lines[1000];
int result;

void find(int a, int b, int n) {
    priority_queue<line, vector<line>, cmp> q;

    int cost1[1000], cost2[1000], cost3[1000];

    for (int i = 0; i <= n; i++) {
        cost1[i] = 800001;
        cost2[i] = 800001;
        cost3[i] = 800001;
    }

    q.push({0, 0});
    cost1[0] = 0;

    while (!q.empty()) {
        int nx = q.top().node;
        int nc = q.top().cost;
        q.pop();

        if (nx == a)
            break;

        for (int i = 0; i < lines[nx].size(); i++) {
            int nn = lines[nx][i].node;
            int nnc = nc + lines[nx][i].cost;

            if (cost1[nn] > nnc) {
                cost1[nn] = nnc;
                q.push({ nn, nnc });
            }
        }
    }
    
    while (!q.empty())
        q.pop();

    q.push({ a, 0 });
    cost2[a] = 0;

    while (!q.empty()) {
        int nx = q.top().node;
        int nc = q.top().cost;
        q.pop();

        if (nx == b)
            break;

        for (int i = 0; i < lines[nx].size(); i++) {
            int nn = lines[nx][i].node;
            int nnc = nc + lines[nx][i].cost;

            if (cost2[nn] > nnc) {
                cost2[nn] = nnc;
                q.push({ nn, nnc });
            }
        }
    }

    while (!q.empty())
        q.pop();

    q.push({ b, 0 });
    cost3[b] = 0;

    while (!q.empty()) {
        int nx = q.top().node;
        int nc = q.top().cost;
        q.pop();

        if (nx == n)
            break;

        for (int i = 0; i < lines[nx].size(); i++) {
            int nn = lines[nx][i].node;
            int nnc = nc + lines[nx][i].cost;

            if (cost3[nn] > nnc) {
                cost3[nn] = nnc;
                q.push({ nn, nnc });
            }
        }
    }

    if ((cost1[a] >= 800001) || (cost2[b] >= 800001) || (cost3[n] >= 800001))
        result = -1;
    else
        result = cost1[a] + cost2[b] + cost3[n];
}

int main() {
    int n, m;
    int a, b;
    int ans;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int startnode, node, cost;

        scanf("%d%d%d", &startnode, &node, &cost);

        lines[startnode - 1].push_back({ node - 1, cost });
        lines[node - 1].push_back({ startnode - 1, cost });
    }

    scanf("%d%d", &a, &b);

    find(a - 1, b - 1, n - 1);
    ans = result;

    find(b - 1, a - 1, n - 1);
    if (result < ans)
        ans = result;
    
    printf("%d\n", ans);

    return 0;
}