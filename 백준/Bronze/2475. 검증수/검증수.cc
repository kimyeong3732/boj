#include <cstdio>

int main() {
    int n, result = 0;
    
    for(int i=0; i<5; i++) {
        scanf("%d", &n);
        result += n*n;
    }
    result = result % 10;
    
    printf("%d\n", result);
    
    return 0;
}