#include <cstdio>

char tri[3072][6145];

void maketri(int a, int b, int n) {
    if (n == 3) {
        tri[a][b] = '*';

        tri[a + 1][b - 1] = '*';
        tri[a + 1][b + 1] = '*';

        tri[a + 2][b - 2] = '*';
        tri[a + 2][b - 1] = '*';
        tri[a + 2][b] = '*';
        tri[a + 2][b + 1] = '*';
        tri[a + 2][b + 2] = '*';

        return;
    }

    int half = n / 2;

    maketri(a, b, half);
    maketri(a + half, b - half, half);
    maketri(a + half, b + half, half);
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (2 * n); j++)
            tri[i][j] = ' ';

    maketri(0, n - 1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (2 * n); j++)
            printf("%c", tri[i][j]);
        printf("\n");
    }

    return 0;
}