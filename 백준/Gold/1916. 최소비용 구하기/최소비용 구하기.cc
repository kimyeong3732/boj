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
int cost[1000];
int result;

void find(int a, int n, int dest) {
    priority_queue<line, vector<line>, cmp> q;

    for (int i = 0; i <= n; i++) {
        cost[i] = 100000001;
    }

    q.push({a, 0});
    cost[a] = 0;

    while (!q.empty()) {
        int nx = q.top().node;
        int nc = q.top().cost;
        q.pop();

        if (nx == dest)
            break;

        for (int i = 0; i < lines[nx].size(); i++) {
            int nn = lines[nx][i].node;
            int nnc = nc + lines[nx][i].cost;

            if (cost[nn] > nnc) {
                cost[nn] = nnc;
                q.push({ nn, nnc });
            }
        }
    }
}

int main() {
    int n, m, start, dest;
    int ans;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int startnode, node, cost;

        scanf("%d%d%d", &startnode, &node, &cost);

        lines[startnode - 1].push_back({ node - 1, cost });
    }

    scanf("%d%d", &start, &dest);

    find(start - 1, n - 1, dest - 1);

    printf("%d\n", cost[dest - 1]);

    return 0;
}