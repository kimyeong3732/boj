#include <cstdio>

int main() {
    int l, a, b, c, d;
    int a2, b2;
    
    scanf("%d%d%d%d%d", &l, &a, &b, &c, &d);
    
    a2 = a / c;
    if((a%c) != 0)
        a2++;
    
    b2 = b / d;
    if((b%d) != 0)
        b2++;
    
    if(b2 > a2)
        a2 = b2;
    
    printf("%d\n", l-a2);
    
    return 0;
}