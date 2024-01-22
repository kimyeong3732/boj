#include <cstdio>

void change(char map[100][100], int r, int c, char RGB, int size) {
    map[r][c] = '0';

    int br[] = { -1, 1, 0, 0 };
    int bc[] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; i++)
        if (((r + br[i]) >= 0) && ((r + br[i]) < size) && ((c + bc[i]) >= 0) && ((c + bc[i]) < size))
            if (map[r + br[i]][c + bc[i]] == RGB)
                change(map, r + br[i], c + bc[i], RGB, size);
}

int findmap(char map[100][100], int size) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (map[i][j] > 'A') {
                change(map, i, j, map[i][j], size);
                result++;
            }
        }
    }

    return result;
}

int main() {
    int n;
    char normap[100][100], abnormap[100][100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", &normap[i]);
        for (int j = 0; j < n; j++) {
            if (normap[i][j] == 'G')
                abnormap[i][j] = 'R';
            else
                abnormap[i][j] = normap[i][j];
        }
    }

    printf("%d %d\n", findmap(normap, n), findmap(abnormap, n));

    return 0;
}