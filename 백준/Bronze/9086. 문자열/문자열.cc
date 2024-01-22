#include <cstdio>

int main() {
    int n;
    char c[1001];
    
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", c);
        printf("%c", c[0]);
        for(int j=0; c[j]; j++)
            if(c[j+1] == 0)
                printf("%c\n", c[j]);
    }
    
    return 0;
}