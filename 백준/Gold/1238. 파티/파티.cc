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

void find(int a, int b) {
    priority_queue<line, vector<line>, cmp> q1, q2;

    int cost1[1000], cost2[1000];

    for (int i = 0; i < 1000; i++) {
        cost1[i] = 100000;
        cost2[i] = 100000;
    }

    q1.push({a, 0});
    cost1[a] = 0;

    while (!q1.empty()) {
        int nx = q1.top().node;
        int nc = q1.top().cost;
        q1.pop();

        if (nx == b)
            break;

        for (int i = 0; i < lines[nx].size(); i++) {
            int nn = lines[nx][i].node;
            int nnc = nc + lines[nx][i].cost;

            if (cost1[nn] > nnc) {
                cost1[nn] = nnc;
                q1.push({ nn, nnc });
            }
        }
    }

    q2.push({ b, 0 });
    cost2[b] = 0;

    while (!q2.empty()) {
        int nx = q2.top().node;
        int nc = q2.top().cost;
        q2.pop();

        if (nx == a)
            break;

        for (int i = 0; i < lines[nx].size(); i++) {
            int nn = lines[nx][i].node;
            int nnc = nc + lines[nx][i].cost;

            if (cost2[nn] > nnc) {
                cost2[nn] = nnc;
                q2.push({ nn, nnc });
            }
        }
    }

    result = cost1[b] + cost2[a];
}

int main() {
    int n, m, x;
    int ans;

    scanf("%d%d%d", &n, &m, &x);

    for (int i = 0; i < m; i++) {
        int startnode, node, cost;
        line temp;

        scanf("%d%d%d", &startnode, &node, &cost);

        temp.node = node - 1;
        temp.cost = cost;

        lines[startnode - 1].push_back(temp);
    }

    find(0, x - 1);
    ans = result;

    for (int i = 1; i < n; i++) {
        find(i, x - 1);

        if (result > ans)
            ans = result;
    }
    
    printf("%d\n", ans);

    return 0;
}