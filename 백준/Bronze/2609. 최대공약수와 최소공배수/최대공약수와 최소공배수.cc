#include <cstdio>

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main() {
    int a, b, gcdVal;
    
    scanf("%d%d", &a, &b);
    
    gcdVal = gcd(a, b);
    
    printf("%d\n%d\n", gcdVal, (a*b)/gcdVal);
    
    return 0;
}