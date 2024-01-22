#include <cstdio>

int main() {
    int n, m;
    int arr[100000];
    
    scanf("%d%d", &n, &m);
    
    for(int i=0; i<n; i++) {
        scanf("%d", arr+i);
        if(i > 0)
            arr[i] += arr[i-1];
    }
    
    for(int i=0; i<m; i++) {
        int a, b;
        
        scanf("%d%d", &a, &b);
        
        if(a != 1)
            printf("%d\n", arr[b-1]-arr[a-2]);
        else
            printf("%d\n", arr[b-1]);
    }
    
    return 0;
}