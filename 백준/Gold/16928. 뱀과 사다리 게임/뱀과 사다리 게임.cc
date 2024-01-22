#include <cstdio>
#include <queue>
using namespace std;

queue<int> q;

void BFS(int map[101], int way[101]) {
    if (q.empty())
        return;

    int num = q.front();
    q.pop();

    for (int i = 1; i <= 6; i++) {
        if (((map[num + i] == 0) || (map[num + i] > (map[num] + 1))) && ((num + i) <= 100)) {
            if (way[num + i] != 0) {
                map[num + i] = 100;
                if ((map[way[num + i]] == 0) || (map[way[num + i]] > (map[num] + 1))) {
                    map[way[num + i]] = map[num] + 1;
                    q.push(way[num + i]);
                }
            }
            else {
                map[num + i] = map[num] + 1;
                q.push(num + i);
            }
        }
    }

    BFS(map, way);
}

int main() {
    int n, m;
    int result[101] = { 0 };
    int way[101] = { 0 };

    scanf("%d%d", &n, &m);

    for (int i = 0; i < (n + m); i++) {
        int index, num;
        scanf("%d%d", &index, &num);
        way[index] = num;
    }

    q.push(1);

    BFS(result, way);

    printf("%d\n", result[100]);

    return 0;
}