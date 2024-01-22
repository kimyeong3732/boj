#include <cstdio>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++)
            printf(" ");
        
        printf("*");
        if(i != 0) {
            for(int j=0; j<(2*i); j++) {
                if((j%2)==0)
                    printf(" ");
                else
                    printf("*");
            }
        }
        printf("\n");
    }
    
    return 0;
}