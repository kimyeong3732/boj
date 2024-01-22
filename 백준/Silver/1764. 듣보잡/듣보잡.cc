#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct names {
    char name[21];
};

bool cmp(names a, names b) {
    if (strcmp(a.name, b.name) < 0)
        return true;
    return false;
}

int main() {
    int n, m;
    names list[500000];
    names list2[500000];
    int size = 0;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%s", &list[i].name);

    sort(list, list + n, cmp);

    for (int i = 0; i < m; i++) {
        char find[21];
        scanf("%s", find);

        int left = 0, right = n - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;

            if (strcmp(list[mid].name, find) < 0)
                left = mid + 1;
            if (strcmp(list[mid].name, find) > 0)
                right = mid - 1;
            if (strcmp(list[mid].name, find) == 0) {
                strcpy(list2[size].name, find);
                size++;
                break;
            }
        }
    }

    sort(list2, list2 + size, cmp);

    printf("%d\n", size);
    for (int i = 0; i < size; i++)
        printf("%s\n", list2[i].name);

    return 0;
}