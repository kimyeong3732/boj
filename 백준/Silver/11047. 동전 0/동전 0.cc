#include <cstdio>

int main() {
    int n, k;
    int arr[10];
    int count = 0;
    
    scanf("%d%d", &n, &k);
    
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    
    int j = n - 1;
    while(k != 0) {
        count += k / arr[j];
        k = k % arr[j];
        j--;
    }
    
    printf("%d\n", count);
    
    return 0;
}