#include <cstdio>

int main() {
    int n, m;
    char arr[11];
    
    scanf("%d%d", &n, &m);
    
    for(int i=0; i<n; i++) {
        scanf("%s", arr);
        
        for(int j=m-1; j>=0; j--)
            printf("%c", arr[j]);
        printf("\n");
    }
    
    return 0;
}