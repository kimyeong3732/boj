#include <cstdio>

int main() {
    int a, b;
    
    scanf("%d%d", &a, &b);
    
    a /= 2;
    b /= 2;
    
    if(a < b)
        printf("%d\n", a);
    else
        printf("%d\n", b);
    
    return 0;
}