#include <cstdio>

int main() {
    int n;
    
    scanf("%d", &n);
    
    printf("%d %d\n", (n/100*78), (n/10*8+n/500*78));
    
    return 0;
}