#include <iostream>
#include <map>
using namespace std;

map<long long, long long> f;

long long find(long long n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (f.count(n) > 0) return f[n];
    
    long long half = n / 2;
    long long f_half = find(half);

    if ((n % 2) == 0) {
        long long f_h_m = find(half - 1);
        f[n] = (f_half * ((2 * f_h_m) + f_half)) % 1000000007;
        return f[n];
    }

    long long f_h_p = find(half + 1);
    f[n] = ((f_h_p * f_h_p) + (f_half * f_half)) % 1000000007;
    return f[n];
}

int main() {
    long long n;

    cin >> n;

    cout << find(n) << '\n';

    return 0;
}