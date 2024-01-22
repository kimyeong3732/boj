#include <cstdio>

int main() {
    int arr[1001];
    
    arr[0] = 0;
    arr[1] = 0;
    
    for(int i=2; i<1001; i++)
        arr[i] = 1;
    
    for(int i=2; i*i<1001; i++) {
        if(arr[i] == 0)
            continue;
        for(int j=i*i; j<1001; j+=i)
            arr[j] = 0;
    }
    
    int n, count = 0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        count += arr[temp];
    }
    
    printf("%d\n", count);
    
    return 0;
}