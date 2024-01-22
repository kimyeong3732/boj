#include <cstdio>

int main() {
    int n;
    int arr[1000001] = {0};
    
    scanf("%d", &n);
    
    arr[2] = 1;
    arr[3] = 1;
    
    for(int i=4; i<=n; i++) {
        int num;
        arr[i] = arr[i-1] + 1;
        
        if((i%2) == 0)
            if(arr[i] > (arr[i/2]+1))
                arr[i] = arr[i/2] + 1;
        
        if((i%3) == 0)
            if(arr[i] > (arr[i/3]+1))
                arr[i] = arr[i/3] + 1;
    }
    
    printf("%d\n", arr[n]);
    
    return 0;
}