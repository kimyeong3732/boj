#include <cstdio>

int main() {
    int T, n;
    
    scanf("%d", &T);
    
    for(int i=0; i<T; i++) {
        int count0a = 1, count1a = 0;
        int count0b = 0, count1b = 1;
        scanf("%d", &n);
        for(int j=1; j<n; j++) {
            int temp0 = count0a + count0b;
            int temp1 = count1a + count1b;
            count0a = count0b;
            count1a = count1b;
            count0b = temp0;
            count1b = temp1;
        }
        
        if(n == 0) {
            count0b = count0a;
            count1b = count1a;
        }
            
        printf("%d %d\n", count0b, count1b);
    }
    
    return 0;
}