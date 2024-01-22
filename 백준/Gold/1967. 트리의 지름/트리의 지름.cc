#include <cstdio>
#include <vector>
using namespace std;

struct line {
    int node;
    int cost;
};

int result = 0, fnode;
vector<line> lines[10000];
int  visit[100000] = { 0 };

void DFS(int node, int cost) {
    if (result < cost) {
        result = cost;
        fnode = node;
    }

    for (int i = 0; i < lines[node].size(); i++) {
        line temp = lines[node][i];
        if (visit[temp.node] == 0) {
            visit[temp.node] = 1;
            DFS(temp.node, cost + temp.cost);
            visit[temp.node] = 0;
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < (n - 1); i++) {
        int node1, node2, cost;

        scanf("%d%d%d", &node1, &node2, &cost);

        lines[node1 - 1].push_back({node2 - 1, cost});
        lines[node2 - 1].push_back({node1 - 1, cost});
    }

    visit[0] = 1;
    DFS(0, 0);
    visit[0] = 0;
    visit[fnode] = 1;
    DFS(fnode, 0);

    printf("%d\n", result);

    return 0;
}