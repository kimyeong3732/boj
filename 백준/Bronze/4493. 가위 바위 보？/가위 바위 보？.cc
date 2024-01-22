#include <cstdio>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int m;
        int aw = 0, bw = 0;
        
        scanf("%d", &m);
        
        for(int j=0; j<m; j++) {
            char a[2], b[2];
            
            scanf("%s%s", a, b);
            
            if(a[0] == 'R') {
                if(b[0] == 'P')
                    bw++;
                else if(b[0] == 'S')
                    aw++;
            }
            
            else if(a[0] == 'P') {
                if(b[0] == 'S')
                    bw++;
                else if(b[0] == 'R')
                    aw++;
            }
            
            else if(a[0] == 'S') {
                if(b[0] == 'R')
                    bw++;
                else if(b[0] == 'P')
                    aw++;
            }
        }
        
        if(aw > bw)
            printf("Player 1\n");
        else if(aw < bw)
            printf("Player 2\n");
        else
            printf("TIE\n");
    }
    
    return 0;
}