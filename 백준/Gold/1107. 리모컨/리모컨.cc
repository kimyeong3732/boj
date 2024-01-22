#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

bool findError(int n, int button[10]) {
    if (n == 0) {
        if (button[0] == 0)
            return false;

        else
            return true;
    }
    else {
        for (int i = n; i > 0; i /= 10)
            if (button[i % 10] == 1)
                return true;

        return false;
    }
}

int main() {
    int n, m;
    int button[10] = { 0 };
    int result;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        button[temp] = 1;
    }

    if (n >= 100)
        result = n - 100;
    else
        result = 100 - n;

    for (int i = 0; i < 1000000 - 100; i++) {
        if (findError(i, button))
            continue;
        int temp = 0;

        if (i == 0)
            temp++;
        for (int j = i; j > 0; j /= 10)
            temp++;

        temp += abs(n - i);

        result = min(result, temp);
    }

    printf("%d\n", result);

    return 0;
}