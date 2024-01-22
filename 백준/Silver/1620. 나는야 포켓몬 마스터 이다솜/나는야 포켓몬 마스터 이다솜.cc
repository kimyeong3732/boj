#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Pocketmon {
    char name[21];
    int index;
};

bool cmp(Pocketmon a, Pocketmon b) {
    if (strcmp(a.name, b.name) < 0)
        return true;
    return false;
}

int main() {
    Pocketmon p[1000000];
    char p2[1000000][21];
    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", &p2[i][0]);
        p[i].index = i;
        strcpy(p[i].name, p2[i]);
    }

    sort(p, p + n, cmp);

    for (int i = 0; i < m; i++) {
        char temp[21];
        scanf("%s", temp);

        if (temp[0] > '9') {
            int left = 0, right = n - 1;
            int mid;

            while (left <= right) {
                mid = (left + right) / 2;
                if (strcmp(p[mid].name, temp) < 0)
                    left = mid + 1;
                if (strcmp(p[mid].name, temp) > 0)
                    right = mid - 1;
                if (strcmp(p[mid].name, temp) == 0) {
                    printf("%d\n", p[mid].index + 1);
                    break;
                }
            }
        }

        else {
            int num = 0;
            for (int j = 0; temp[j]; j++) {
                num *= 10;
                num += temp[j] - '0';
            }
            printf("%s\n", p2[num - 1]);
        }
    }

    return 0;
}