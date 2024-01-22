#include <cstdio>

int main() {
    int a, b, c, d;
    int result;
    
    scanf("%d%d%d%d", &a, &b, &c, &d);
    
    result = a + d - b - c;
    
    if(result < 0)
        result *= -1;
    
    printf("%d\n", result);
    
    return 0;
}