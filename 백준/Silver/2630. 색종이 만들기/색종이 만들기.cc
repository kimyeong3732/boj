#include <cstdio>

void find(int map[128][128], int n, int br, int bc, int* count0, int* count1) {
    int state = 0;
    int match = map[br][bc];

    for (int i = br; i < (br + n); i++) {
        for (int j = bc; j < (bc + n); j++) {
            if (map[i][j] != match) {
                state = 1;
                break;
            }
        }
    }

    if (state == 1) {
        n /= 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                find(map, n, br + (n * i), bc + (n * j), count0, count1);
            }
        }
    }
    else {
        if (match == 0)
            (*count0)++;
        if (match == 1)
            (*count1)++;
    }
}

int main() {
    int n;
    int map[128][128];
    int count0 = 0, count1 = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);

    find(map, n, 0, 0, &count0, &count1);

    printf("%d\n%d\n", count0, count1);

    return 0;
}