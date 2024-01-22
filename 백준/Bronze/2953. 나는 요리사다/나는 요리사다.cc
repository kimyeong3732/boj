#include <cstdio>

int main() {
    int max = 0, mi = 0;
    
    for(int i=0; i<5; i++) {
        int sum = 0;
        
        for(int j=0; j<4; j++) {
            int num;
            
            scanf("%d", &num);
            
            sum += num;
        }
        
        if(sum > max) {
            max = sum;
            mi = i + 1;
        }
    }
    
    printf("%d %d\n", mi, max);
    
    return 0;
}