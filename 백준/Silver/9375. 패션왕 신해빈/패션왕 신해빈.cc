#include <cstdio>
#include <cstring>

struct cloth {
    int num;
    char cloth[21];
};

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m, index = 0;
        int result = 1;
        cloth cloths[30];

        scanf("%d", &m);

        for (int j = 0; j < m; j++) {
            int k = 0;
            char a[21], b[21];

            scanf("%s%s", a, b);

            for (k; k < index; k++) {
                if (strcmp(b, cloths[k].cloth) == 0) {
                    break;
                }
            }

            if (k == index) {
                cloths[index].num = 1;
                strcpy(cloths[index].cloth, b);
                index++;
            }
            else {
                cloths[k].num++;
            }
        }

        for (int j = 0; j < index; j++) {
            result *= cloths[j].num + 1;
        }

        result--;

        printf("%d\n", result);
    }

    return 0;
}