#include <cstdio>

int main() {
    int c, k, p;
    int sum = 0;
    
    scanf("%d%d%d", &c, &k, &p);
    
    for(int i=1; i<=c; i++)
        sum += (k*i) + (p*i*i);
    
    printf("%d\n", sum);
    
    return 0;
}