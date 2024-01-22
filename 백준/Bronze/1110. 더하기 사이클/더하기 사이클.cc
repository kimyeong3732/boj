#include <cstdio>

int main() {
    int n;
    int temp;
    int count = 1;

    scanf("%d", &n);
    temp = n%10*10 + (n/10 + n%10)%10;

    while(n != temp) {
        temp = temp%10*10 + (temp/10 + temp%10)%10;
        count++;
    }

    printf("%d\n", count);
    return 0;
}