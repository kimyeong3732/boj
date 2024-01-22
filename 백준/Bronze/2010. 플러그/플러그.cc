#include <cstdio>

int main() {
    int n;
    int result = 1;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int num;
        
        scanf("%d", &num);
        
        result--;
        result += num;
    }
    
    printf("%d\n", result);
    
    return 0;
}