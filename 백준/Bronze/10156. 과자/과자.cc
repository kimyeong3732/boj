#include <cstdio>

int main() {
    int a, b, c;
    
    scanf("%d%d%d", &a, &b, &c);
    
    if(c >= (a*b))
        printf("0\n");
    else
        printf("%d\n", (a*b)-c);
    
    return 0;
}