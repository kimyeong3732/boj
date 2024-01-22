#include <cstdio>

int main() {
    int min = 1000000;
    int max =  -1000000;
    int n, temp;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &temp);
        
        if(min > temp) min = temp;
        if(max < temp) max = temp;
    }
    
    printf("%d %d\n", min, max);
    
    return 0;
}