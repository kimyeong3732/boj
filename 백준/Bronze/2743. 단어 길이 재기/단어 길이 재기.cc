#include <cstdio>

int main() {
    char c[101];
    int i = 0,count = 0;

    scanf("%s", c);
    while (c[i++] != 0) count++;
    printf("%d\n", count);
    return 0;
}