#include <cstdio>

int main() {
    int n;
    int max[3], min[3];
    int resultx, resultn;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b, c;

        scanf("%d%d%d", &a, &b, &c);

        if (i == 0) {
            max[0] = a;
            max[1] = b;
            max[2] = c;

            min[0] = a;
            min[1] = b;
            min[2] = c;
        }

        else {
            int ax = a + max[1];
            int bx = b + max[1];
            int cx = c + max[1];
            int an = a + min[1];
            int bn = b + min[1];
            int cn = c + min[1];

            if ((a + max[0]) > ax)
                ax = a + max[0];
            if ((b + max[0]) > bx)
                bx = b + max[0];
            if ((b + max[2]) > bx)
                bx = b + max[2];
            if ((c + max[2]) > cx)
                cx = c + max[2];

            if ((a + min[0]) < an)
                an = a + min[0];
            if ((b + min[0]) < bn)
                bn = b + min[0];
            if ((b + min[2]) < bn)
                bn = b + min[2];
            if ((c + min[2]) < cn)
                cn = c + min[2];

            max[0] = ax;
            max[1] = bx;
            max[2] = cx;

            min[0] = an;
            min[1] = bn;
            min[2] = cn;
        }
    }

    resultx = max[0];
    resultn = min[0];

    if (resultx < max[1])
        resultx = max[1];
    if (resultx < max[2])
        resultx = max[2];

    if (resultn > min[1])
        resultn = min[1];
    if (resultn > min[2])
        resultn = min[2];

    printf("%d %d\n", resultx, resultn);

    return 0;
}