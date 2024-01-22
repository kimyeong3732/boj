#include <cstdio>

int main() {
    int n, m;
    char s[1000001];
    int count = 0, i = 0, p = 0;

    scanf("%d%d", &n, &m);
    scanf("%s", s);

    while (i < (m - 2)) {
        if (s[i] == 'O') {
            i++;
            p = 0;
        }
        else {
            if ((s[i + 1] == 'O') && (s[i + 2] == 'I')) {
                p++;
                if (p == n) {
                    count++;
                    p--;
                }
                i += 2;
            }
            else {
                p = 0;
                i++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}