#include <cstdio>

int main() {
    int a, b, c;
    
    scanf("%d%d", &a, &b);
    scanf("%d", &c);
    
    if((a+b) >= (c*2))
        printf("%d\n", (a+b)-(c*2));
    else
        printf("%d\n", a+b);
    
    return 0;
}