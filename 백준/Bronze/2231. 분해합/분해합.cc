#include <cstdio>

int main() {
    int n, found = 0;
    
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) {
        int num = i;
        
        for(int j=i; j>0; j/=10)
            num += j % 10;
        
        if(num == n) {
            found = 1;
            printf("%d\n", i);
            break;
        }
    }
    
    if(found == 0)
        printf("0\n");
    
    return 0;
}