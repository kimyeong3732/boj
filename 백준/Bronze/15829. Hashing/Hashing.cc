#include <cstdio>

int main() {
    int n;
    long long result = 0;
    char *c;

    scanf("%d", &n);
    c = new char[n + 1];
    scanf("%s", c);
    for (int i = 0; i < n; i++) {
        long long temp;
        temp = c[i] - 'a' + 1;
        for (int j = 0; j < i; j++) {
            temp *= 31;
            if (temp >= 1234567891)
                temp = temp % 1234567891;
        }
        result = (result + temp) % 1234567891;
    }

    printf("%lld\n", result);
    
    return 0;
}