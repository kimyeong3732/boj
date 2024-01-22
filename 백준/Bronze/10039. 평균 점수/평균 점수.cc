#include <cstdio>

int main() {
    int n;
    int sum = 0;
    
    for(int i=0; i<5; i++) {
        scanf("%d", &n);
        
        if(n < 40)
            sum += 40;
        else
            sum += n;
    }
    
    printf("%d\n", sum/5);
    
    return 0;
}