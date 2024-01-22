#include <cstdio>

int main() {
    int n;
    int weight[50], ki[50];
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%d%d", weight+i, ki+i);
    
    for(int i=0; i<n; i++) {
        int count = 1;
        for(int j=0; j<n; j++) {
            if(i == j)
                continue;
            if((weight[i]<weight[j]) && (ki[i]<ki[j]))
                count++;
        }
        printf("%d ", count);
    }
    
    printf("\n");
    
    return 0;
}