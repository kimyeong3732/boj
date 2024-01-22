#include <cstdio>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int num;
        int sum = 0;
        int t = 1;
        
        scanf("%d", &num);
        
        for(int j=0; j<num; j++) {
            t += j + 2;
            sum += (j + 1) * t;
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}