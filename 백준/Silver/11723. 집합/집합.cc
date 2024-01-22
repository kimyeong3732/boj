#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n;
    char cmd[7];
    int num;
    int s[20] = { 0 };

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            scanf("%d", &num);
            if (s[num - 1] == 0)
                s[num - 1] = 1;
        }
        else if (strcmp(cmd, "remove") == 0) {
            scanf("%d", &num);
            if (s[num - 1] == 1)
                s[num - 1] = 0;
        }
        else if (strcmp(cmd, "check") == 0) {
            scanf("%d", &num);
            printf("%d\n", s[num - 1]);
        }
        else if (strcmp(cmd, "toggle") == 0) {
            scanf("%d", &num);
            if (s[num - 1] == 0)
                s[num - 1] = 1;
            else
                s[num - 1] = 0;
        }
        else if (strcmp(cmd, "all") == 0) {
            for (int j = 0; j < 20; j++)
                s[j] = 1;
        }
        else if(strcmp(cmd, "empty") == 0) {
            for (int j = 0; j < 20; j++)
                s[j] = 0;
        }
    }

    return 0;
}