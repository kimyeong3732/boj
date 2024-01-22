#include <iostream>
using namespace std;

int main() {
    int n, result;
    int arr[1000];
    int dp[1000];
    int dp_r[1000] = { 0 };

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = 1;
    dp_r[0] = 1;

    for (int i = 1; i < n; i++) {
        int max = 0;
        int max_r = -1;
        for (int j = 0; j < i; j++) {
            if ((arr[j] < arr[i]) && (dp[j] > max))
                max = dp[j];

            if (arr[j] > arr[i]) {
                if (dp[j] > max_r)
                    max_r = dp[j];
                
                if (dp_r[j] > max_r)
                    max_r = dp_r[j];
            }
        }

        dp[i] = max + 1;
        dp_r[i] = max_r + 1;
    }

    result = dp[0];
    for (int i = 1; i < n; i++) {
        if (dp[i] > result)
            result = dp[i];

        if (dp_r[i] > result)
            result = dp_r[i];
    }

    cout << result << '\n';

    return 0;
}