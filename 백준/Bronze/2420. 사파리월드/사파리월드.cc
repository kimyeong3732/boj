#include <cstdio>

int main() {
    long long a, b, result;
    
    scanf("%lld%lld", &a, &b);
    
    result = a - b;
    if(result < 0) result = result * (-1);
    
    printf("%lld\n", result);
    
    return 0;
}