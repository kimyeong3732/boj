#include <cstdio>

int main() {
    int n, max = 0;
    
    for(int i=0; i<9; i++) {
        int temp;
        scanf("%d", &temp);
        
        if(max < temp) {
            max = temp;
            n = i + 1;
        }
    }
    
    printf("%d\n%d\n", max, n);
    
    return 0;
}