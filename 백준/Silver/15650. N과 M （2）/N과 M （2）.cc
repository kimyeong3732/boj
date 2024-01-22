#include <cstdio>

int n, m;
int arr[8];

void DFS(int a, int count) {
    int rest = m - count;

    if (rest == 0) {
        for (int i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i = a; i <= n; i++) {
        if ((n - a) >= (rest - 1)) {
            arr[count] = i;
            DFS(i + 1, count + 1);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    DFS(1, 0);
    
    return 0;
}