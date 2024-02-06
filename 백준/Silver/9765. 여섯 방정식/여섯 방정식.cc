#include <cstdio>

long long gcd(long long a, long long b) {
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

int main() {
    long long c[6];
    
    for(int i=0; i<6; i++) {
        scanf("%lld", c+i);
    }
    
    long long x[6];
    
    x[1] = gcd(c[0], c[4]);
    x[0] = c[0] / x[1];
    x[2] = c[4] / x[1];
    
    x[4] = gcd(c[5], c[2]);
    x[3] = c[5] / x[4];
    x[5] = c[2] / x[4];
    
    for(int i=0; i<6; i++)
        printf("%lld ", x[i]);
    
    printf("\n");
    
    return 0;
}