#include <cstdio>
#include <queue>
using namespace std;

struct numcount {
    int num;
    int count;
};

void BFS(int n, int m) {
    int mul2 = n * 2;
    queue<numcount> q;

    q.push({m, 1});

    while (!q.empty()) {
        int num = q.front().num;
        int count = q.front().count;
        q.pop();

        if (num == n) {
            printf("%d\n", count);
            return;
        }

        if (mul2 <= num) {
            if ((num % 2) == 0)
                q.push({ num / 2, count + 1 });

            if ((num % 10) == 1)
                q.push({ (num - 1) / 10, count + 1 });
        }
    }

    printf("-1\n");
}

int main() {
    int n, m;

    scanf("%d%d", &n, &m);
    
    BFS(n, m);

    return 0;
}