#include <cstdio>

int main() {
    int n, score = 0;
    int t = 0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int m;
        
        scanf("%d", &m);
        
        if(m == 1) {
            t++;
            score += t;
        }
        else
            t = 0;
    }
    
    printf("%d\n", score);
    
    return 0;
}