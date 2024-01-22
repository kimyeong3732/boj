#include <cstdio>

int main() {
    int n, m, arr[1000001];

    arr[0] = 0;
    arr[1] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= m; i++)
        arr[i] = 1;
    for (int i = 2; i * i <= m; i++) {
        if (arr[i] == 0)
            continue;
        for (int j = i * i; j <= m; j += i)
            arr[j] = 0;
    }

    for (int i = n; i <= m; i++)
        if (arr[i] == 1)
            printf("%d\n", i);
    
    return 0;
}