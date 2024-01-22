#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int result;
    int R[1001] = { 0 };
    int G[1001] = { 0 };
    int B[1001] = { 0 };


    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int cost[3];

        for (int j = 0; j < 3; j++)
            scanf("%d", cost + j);

        R[i] = min(G[i - 1], B[i - 1]) + cost[0];
        G[i] = min(R[i - 1], B[i - 1]) + cost[1];
        B[i] = min(R[i - 1], G[i - 1]) + cost[2];
    }
    result = min(R[n], min(G[n], B[n]));

    printf("%d\n", result);

    return 0;
}