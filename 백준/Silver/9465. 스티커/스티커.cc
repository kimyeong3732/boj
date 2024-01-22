#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, l;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int arr[2][100000];
        int result[2][100001] = { 0 };

        scanf("%d", &l);
        for(int j=0; j<2; j++)
            for (int k = 0; k < l; k++)
                scanf("%d", &arr[j][k]);

        result[0][l - 1] = arr[0][l - 1];
        result[1][l - 1] = arr[1][l - 1];

        for (int j = l - 2; j >= 0; j--) {
            result[0][j] = max(result[1][j + 1], result[1][j + 2]) + arr[0][j];
            result[1][j] = max(result[0][j + 1], result[0][j + 2]) + arr[1][j];
        }

        printf("%d\n", max(result[0][0], result[1][0]));
    }

    return 0;
}