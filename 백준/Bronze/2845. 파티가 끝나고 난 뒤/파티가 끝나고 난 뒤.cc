#include <cstdio>

int main() {
    int a, b;
    
    scanf("%d%d", &a, &b);
    
    a *= b;
    
    for(int i=0; i<5; i++) {
        int temp;
        
        scanf("%d", &temp);
        
        printf("%d ", temp-a);
    }
    printf("\n");
    
    return 0;
}