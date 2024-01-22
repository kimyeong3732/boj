#include <cstdio>
#include <vector>
using namespace std;

int find(int parent[51], int a) {
    if (parent[a] == a)
        return a;
    return find(parent, parent[a]);
}

void merge(int parent[51], int a, int b) {
    int x = find(parent, a);
    int y = find(parent, b);

    parent[y] = x;
}

int main() {
    int n, m, knownum;
    vector<int> knowman;
    vector<int> party[50];
    int parent[51];
    int result = 0;

    scanf("%d%d", &n, &m);
    scanf("%d", &knownum);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < knownum; i++) {
        int temp;
        scanf("%d", &temp);

        knowman.push_back(temp);
    }

    for (int i = 0; i < m; i++) {
        int p;
        scanf("%d", &p);

        for (int j = 0; j < p; j++) {
            int temp;
            scanf("%d", &temp);

            party[i].push_back(temp);
        }
    }

    for (int i = 0; i < m; i++) {
        int a = party[i][0];

        for (int j = 1; j < party[i].size(); j++) {
            int b = party[i][j];

            merge(parent, a, b);
        }
    }

    for (int i = 0; i < m; i++) {
        int state = 0;

        for (int j = 0; j < knowman.size(); j++) {
            if (find(parent, knowman[j]) == find(parent, party[i][0])) {
                state = 1;
                break;
            }
        }

        if (state == 0)
            result++;
    }

    printf("%d\n", result);

    return 0;
}