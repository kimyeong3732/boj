#include <cstdio>
#include <algorithm>
using namespace std;

void find(int n, int map[25][25], int br, int bc, int building[25], int *size, int order) {
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, -1, 0, 1 };

    if (order == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1) {
                    find(n, map, i, j, building, size, 1);
                    (*size)++;
                }
            }
        }
    }

    else {
        map[br][bc] = 0;
        building[*size]++;

        for (int i = 0; i < 4; i++) {
            int r = br + dr[i];
            int c = bc + dc[i];

            if ((r >= 0) && (r < n) && (c >= 0) && (c < n)) {
                if (map[r][c] == 1)
                    find(n, map, r, c, building, size, 1);
            }
        }
    }
}

int main() {
    int n;
    int map[25][25];
    int building[25] = { 0 };
    int size = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char temp[26];
        scanf("%s", temp);
        for (int j = 0; j < n; j++) {
            map[i][j] = temp[j] - '0';
        }
    }

    find(n, map, 0, 0, building, &size, 0);

    sort(building, building + size);

    printf("%d\n", size);

    for (int i = 0; i < size; i++) {
        printf("%d\n", building[i]);
    }

    return 0;
}