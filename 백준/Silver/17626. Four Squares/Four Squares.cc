#include <cstdio>

int main() {
    int n;
    int arr[50001] = { 0 };

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 1; (i + (j * j)) <= n; j++) {
            int temp = i + (j * j);
            if ((arr[temp] == 0) || (arr[temp] > (arr[i] + 1)))
                arr[temp] = arr[i] + 1;
        }
    }

    printf("%d\n", arr[n]);

    return 0;
}