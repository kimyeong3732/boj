#include <cstdio>

void findline(int mat[100][100], int size, int a, int b, int visit[100][100]) {
    for (int i = 0; i < size; i++) {
        if ((mat[b][i] == 1) && (visit[a][i] == 0)) {
            mat[a][i] = 1;
            visit[a][i] = 1;
            findline(mat, size, a, i, visit);
        }
    }
}

void find(int mat[100][100], int size, int visit[100][100]) {
    for (int i = 0; i < size; i++)
        findline(mat, size, i, i, visit);
}

int main() {
    int n;
    int mat[100][100];
    int visit[100][100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            visit[i][j] = 0;
        }
    }

    find(mat, n, visit);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}