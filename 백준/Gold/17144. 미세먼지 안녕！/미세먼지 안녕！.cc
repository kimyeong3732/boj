#include <cstdio>

int room[50][50];

void dust(int r, int c) {
    int cal[50][50] = { 0 };
    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (room[i][j] > 4) {
                int spread = room[i][j] / 5;
                int count = 0;

                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if ((nr >= 0) && (nr < r) && (nc >= 0) && (nc < c) && (room[nr][nc] != -1)) {
                        cal[nr][nc] += spread;
                        count++;
                    }
                }

                cal[i][j] -= spread * count;
            }
        }
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (room[i][j] != -1)
                room[i][j] += cal[i][j];
}

void machine(int r, int c, int top) {
    for (int i = top - 1; i > 0; i--)
        room[i][0] = room[i - 1][0];

    for (int i = 0; i < (c - 1); i++)
        room[0][i] = room[0][i + 1];

    for (int i = 0; i < top; i++)
        room[i][c - 1] = room[i + 1][c - 1];

    for (int i = c - 1; i > 1; i--)
        room[top][i] = room[top][i - 1];

    room[top][1] = 0;

    for (int i = top + 2; i < (r - 1); i++)
        room[i][0] = room[i + 1][0];

    for (int i = 0; i < (c - 1); i++)
        room[r-1][i] = room[r-1][i + 1];

    for (int i = r - 1; i > (top + 1); i--)
        room[i][c - 1] = room[i - 1][c - 1];

    for (int i = c - 1; i > 1; i--)
        room[top + 1][i] = room[top + 1][i - 1];

    room[top + 1][1] = 0;
}

int main() {
    int r, c, t;
    int top;
    int result = 0;

    scanf("%d%d%d", &r, &c, &t);
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &room[i][j]);

    for (int i = 0; i < r; i++) {
        if (room[i][0] == -1) {
            top = i;
            break;
        }
    }

    for (int i = 0; i < t; i++) {
        dust(r, c);
        machine(r, c, top);
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (room[i][j] > 0)
                result += room[i][j];

    printf("%d\n", result);

    return 0;
}