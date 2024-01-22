#include <cstdio>

int main() {
    int s, t, d;
    
    scanf("%d%d%d", &s, &t, &d);
    
    printf("%d\n", (d/(s*2))*t);
    
    return 0;
}