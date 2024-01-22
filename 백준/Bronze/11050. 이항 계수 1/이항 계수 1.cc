#include <cstdio>

int main() {
    int n, k;
    int up = 1, down = 1;
    
    scanf("%d%d", &n, &k);
    
    for(int i=0; i<k; i++) {
        up *= n;
        n--;
    }
    for(int i=2; i<=k; i++)
        down *= i;
    
    printf("%d\n", up/down);
    
    return 0;
}