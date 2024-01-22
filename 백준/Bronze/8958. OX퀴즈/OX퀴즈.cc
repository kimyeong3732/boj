#include <cstdio>

int main() {
    int n;
    char c[80];
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int numO = 1;
        int score = 0;
        
        scanf("%s", c);
        for(int j=0; c[j]; j++) {
            if(c[j] == 'O') {
                score += numO;
                numO++;
            }
            else
                numO = 1;
        }
        printf("%d\n", score);
    }
    
    return 0;
}