#include <cstdio>

int main() {
    int n;
    int sum = 0;
    
    while(scanf("%d", &n) != -1)
        sum += n;
    
    printf("%d\n", sum);
    
    return 0;
}