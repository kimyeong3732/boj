#include <cstdio>

long long GCD(long long a, long long b) {
    if ((a % b) == 0)
        return b;

    return GCD(b, a % b);
}

long long mul(long long a, long long mt) {
    if (mt == 1)
        return a;

    if ((mt % 2) == 1)
        return a * mul(a, mt - 1) % 1000000007;

    long long temp = mul(a, mt / 2);

    return temp * temp % 1000000007;
}

int main() {
    int n;
    long long num, sum, result = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &num, &sum);

        if ((sum % num) == 0)
            result += sum / num;

        else {
            long long g = GCD(num, sum);
            num /= g;
            sum /= g;

            result += sum * mul(num, 1000000005) % 1000000007;
        }

        result %= 1000000007;
    }

    printf("%lld\n", result);

    return 0;
}