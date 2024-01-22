#include <cstdio>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int num, ind = 0;
        
        scanf("%d", &num);
        
        while(num > 0) {
            if((num%2) == 1) {
                printf("%d ", ind);
            }
            ind++;
            num /= 2;
        }
        printf("\n");
    }
    
    return 0;
}