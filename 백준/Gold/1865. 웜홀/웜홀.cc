#include <cstdio>
#include <vector>
using namespace std;

struct line {
    int start;
    int end;
    int cost;
};

void find(int size, vector<line> lines) {
    int cost[500];

    for (int i = 0; i < size; i++) {
        cost[i] = 5000001;
    }

    cost[0] = 0;

    for(int i=0; i<(size-1); i++) {
        for (int j = 0; j < lines.size(); j++) {
            int s = lines[j].start;
            int e = lines[j].end;
            int c = lines[j].cost;

            if (cost[e] > (cost[s] + c))
                cost[e] = cost[s] + c;
        }
    }

    for(int i=0; i<lines.size(); i++) {
        int s = lines[i].start;
        int e = lines[i].end;
        int c = lines[i].cost;

        if (cost[e] > (cost[s] + c)) {
            printf("YES\n");
            return;
        }
    }

    printf("NO\n");
}

int main() {
    int n;
    int ans;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int size, r, w;
        vector<line> lines;

        scanf("%d%d%d", &size, &r, &w);

        for (int j = 0; j < r; j++) {
            int startnode, node, cost;

            scanf("%d%d%d", &startnode, &node, &cost);

            lines.push_back({ startnode - 1, node - 1, cost });
            lines.push_back({ node - 1, startnode - 1, cost });
        }
        for (int j = 0; j < w; j++) {
            int startnode, node, cost;

            scanf("%d%d%d", &startnode, &node, &cost);

            lines.push_back({ startnode - 1, node - 1, -cost });
        }

        find(size, lines);
    }

    return 0;
}