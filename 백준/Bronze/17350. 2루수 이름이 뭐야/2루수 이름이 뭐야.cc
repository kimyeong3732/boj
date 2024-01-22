#include <cstdio>
#include <cstring>

int main() {
    char anj[] = "anj";
    int n, state = 0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        char s[100];
        
        scanf("%s", s);
        
        if(strcmp(s, anj) == 0)
            state = 1;
    }
    
    printf("뭐야");
    
    if(state == 1)
        printf(";\n");
    else
        printf("?\n");
    
    return 0;
}