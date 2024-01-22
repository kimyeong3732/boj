#include <cstdio>

int main() {
    int ball = 1;
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int a, b;
        
        scanf("%d%d", &a, &b);
        
        if(a == ball)
            ball = b;
        else if(b == ball)
            ball = a;
    }
    
    printf("%d\n", ball);
    
    return 0;
}