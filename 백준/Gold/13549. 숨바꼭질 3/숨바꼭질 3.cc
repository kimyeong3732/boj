#include <cstdio>
#include <queue>
using namespace std;

void BFS(int n, int m) {
    int count = 0;
    int cnt[200001];
    queue <int> q;

    for (int i = 0; i <= 200000; i++)
        cnt[i] = 100001;

    cnt[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int nc = q.front();
        q.pop();

        if (nc == m) {
            if (count == 0)
                printf("%d\n", cnt[m]);

            count++;
            break;
        }

        if ((nc > 0) && (cnt[nc - 1] >= (cnt[nc] + 1))) {
            cnt[nc - 1] = cnt[nc] + 1;
            q.push(nc - 1);
        }

        if (nc < m) {
            if (cnt[nc + 1] >= (cnt[nc] + 1)) {
                cnt[nc + 1] = cnt[nc] + 1;
                q.push(nc + 1);
            }

            if (cnt[nc * 2] >= (cnt[nc] + 1)) {
                cnt[nc * 2] = cnt[nc];
                q.push(nc * 2);
            }
        }
    }
}

int main() {
    int n, m;

    scanf("%d%d", &n, &m);

    BFS(n, m);

    return 0;
}