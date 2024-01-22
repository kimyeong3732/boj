#include <cstdio>

int arr[1024][1024];

int main() {
    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;

            scanf("%d", &temp);

            arr[i][j] = temp;
        }
    }

    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] += arr[i - 1][j];

    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            arr[i][j] += arr[i][j - 1];

    for (int i = 0; i < m; i++) {
        int x1, x2, y1, y2;
        int result;

        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        result = arr[x2 - 1][y2 - 1];

        if ((x1 > 1) && (y1 > 1))
            result += arr[x1 - 2][y1 - 2];

        if (x1 > 1)
            result -= arr[x1 - 2][y2 - 1];

        if (y1 > 1)
            result -= arr[x2 - 1][y1 - 2];
        
        printf("%d\n", result);
    }

    return 0;
}