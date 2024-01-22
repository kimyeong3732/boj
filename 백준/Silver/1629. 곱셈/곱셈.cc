#include <cstdio>

int a, b, c;

long long find(int b) {
    if(b == 1)
        return a%c;
    
    long long num = find(b/2)%c;
    
    if((b%2) == 0)
        return num*num%c;
    return num*num%c*a%c;
}

int main() {
    scanf("%d%d%d", &a, &b, &c);
    
    printf("%lld\n", find(b));
    
    return 0;
}