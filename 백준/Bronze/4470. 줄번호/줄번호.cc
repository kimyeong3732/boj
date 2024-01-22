#include <cstdio>

int main() {
    int t;
    char c[51];
    
    scanf("%d", &t);
    
    for(int i=0; i<t; i++) {
        scanf("%c", c);
        scanf("%[^\n]s", c);
        
        printf("%d. %s\n", i+1, c);
    }
    
    return 0;
}