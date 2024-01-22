#include <cstdio>

int main() {
    int n, k;
    int num = 0;
    
    scanf("%d%d", &n, &k);
    
    for(int i=1; i<=n; i++) {
        if((n%i) == 0) {
            num++;
        }
        if(num == k) {
            printf("%d\n", i);
            break;
        }
    }
    
    if(num != k)
        printf("0\n");
    
    return 0;
}