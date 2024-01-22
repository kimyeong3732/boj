#include <cstdio>

int main() {
    int n, m;
    char c[21];
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        scanf("%d%s", &m, c);
        
        for(int j=0; c[j]; j++)
            for(int k=0; k<m; k++)
                printf("%c", c[j]);
        printf("\n");
    }
    
    return 0;
}