#include <cstdio>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void calender(int m, int n, int x, int y) {
    int lcm = m * n / gcd(m, n);
    int numm = lcm / m, numn = lcm / n;
    int a = x, b = y;
    int i = 0, j = 0;

    while ((i < numm) && (j < numn)) {
        if (a > b) {
            b += n;
            j++;
        }
        else if (a < b) {
            a += m;
            i++;
        }
        else {
            printf("%d\n", a);
            return;
        }
    }

    printf("-1\n");
}

int main() {
    int t;
    
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int m, n, x, y;
        scanf("%d%d%d%d", &m, &n, &x, &y);

        calender(m, n, x, y);
    }

    return 0;
}