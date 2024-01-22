#include <cstdio>

int main() {
    int n, result = 1;
    
    scanf("%d", &n);
    
    for(int i=2; i<=n; i++) result *= i;
    
    printf("%d\n", result);
    
    return 0;
}