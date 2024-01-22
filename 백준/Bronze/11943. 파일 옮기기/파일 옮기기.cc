#include <cstdio>

int main() {
    int a1, a2, b1, b2;
    
    scanf("%d%d", &a1, &b1);
    scanf("%d%d", &a2, &b2);
    
    if((a1+b2) > (a2+b1))
        printf("%d\n", a2+b1);
    else
        printf("%d\n", a1+b2);
    
    return 0;
}