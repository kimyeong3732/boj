#include <cstdio>

void QuadTree(int map[64][64], int n, int br, int bc) {
    int state = map[br][bc];

    for (int i = br; i < (br + n); i++) {
        for (int j = bc; j < (bc + n); j++) {
            if (state != map[i][j]) {
                state = map[i][j];
                break;
            }
        }

        if (state != map[br][bc]) {
            break;
        }
    }

    if (state == map[br][bc])
        printf("%d", state);
    else {
        int r[4] = { 0, 0, n / 2, n / 2 };
        int c[4] = { 0, n / 2, 0, n / 2 };

        printf("(");
        for (int i = 0; i < 4; i++)
            QuadTree(map, n / 2, br + r[i], bc + c[i]);
        printf(")");
    }
}

int main() {
    int n;
    int map[64][64];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char temp[65];
        scanf("%s", temp);
        for (int j = 0; j < n; j++) {
            map[i][j] = temp[j] - '0';
        }
    }

    QuadTree(map, n, 0, 0);
    printf("\n");

    return 0;
}