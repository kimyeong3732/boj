#include <cstdio>

int main() {
    int n, m;
    int arr[100] = {0};
    
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        int a, b, c;
        
        scanf("%d%d%d", &a, &b, &c);
        
        for(int j=a-1; j<b; j++)
            arr[j] = c;
    }
    
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}