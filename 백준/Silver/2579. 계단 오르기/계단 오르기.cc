#include <cstdio>

int main() {
    int n;
    int scores[301];
    int dp[301] = { 0 };

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", scores + i);

    dp[n] = scores[n];

    for (int i = n; i > 0; i--) {
        if (i > 2) {
            if (dp[i - 3] < (dp[i] + scores[i - 1] + scores[i - 3]))
                dp[i - 3] = dp[i] + scores[i - 1] + scores[i - 3];
            if (dp[i - 2] < (dp[i] + scores[i - 2]))
                dp[i - 2] = dp[i] + scores[i - 2];
        }
        else {
            if (i == 2) {
                if (dp[i - 2] < (dp[i] + scores[i - 1]))
                    dp[i - 2] = dp[i] + scores[i - 1];
                if (dp[i - 2] < dp[i])
                    dp[i - 2] = dp[i];
            }
            else {
                if (dp[i - 1] < dp[i])
                    dp[i - 1] = dp[i];
            }
        }
    }

    printf("%d\n", dp[0]);

    return 0;
}