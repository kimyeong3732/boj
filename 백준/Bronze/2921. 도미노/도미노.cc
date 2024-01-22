#include <cstdio>

int main() {
    int n;
    int sum = 0;
    
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)
        for(int j=0; j<=i; j++)
            sum += i + j;
    
    printf("%d\n", sum);
    
    return 0;
}