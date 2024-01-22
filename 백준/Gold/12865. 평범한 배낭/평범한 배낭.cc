#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    int wv[2][101];
    int dp[101][100001] = { 0 };

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++)
        scanf("%d%d", &wv[0][i], &wv[1][i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if ((j - wv[0][i]) >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wv[0][i]] + wv[1][i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    printf("%d\n", dp[n][k]);

    return 0;
}