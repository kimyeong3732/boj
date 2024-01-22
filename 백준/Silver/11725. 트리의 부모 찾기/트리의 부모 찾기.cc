#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[100000];
int visit[100000] = { 0 };
int parent[100000];

void BFS() {
    queue<int> q;

    visit[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (int i = 0; i < v[a].size(); i++) {
            int num = v[a][i];

            if (visit[num] == 0) {
                visit[num] = 1;
                parent[num] = a;
                q.push(num);
            }
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    for(int i=1; i<n; i++) {
        int a, b;

        scanf("%d%d", &a, &b);
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    BFS();

    for (int i = 1; i < n; i++)
        printf("%d\n", parent[i] + 1);

    return 0;
}