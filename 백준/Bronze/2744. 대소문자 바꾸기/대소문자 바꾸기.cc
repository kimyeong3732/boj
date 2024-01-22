#include <cstdio>

int main() {
    char c[101];
    int i = 0, n = 'a' - 'A';

    scanf("%s", c);
    while (c[i] != 0) {
        if(c[i] < 'a') c[i] += n;
        else c[i] -= n;
        i++;
    }
    printf("%s\n", c);
    return 0;
}