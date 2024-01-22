#include <cstdio>

int main() {
    int n, num;
    long long arr[100] = {1, 1, 1, 2, 2};
    
    for(int i=5; i<100; i++)
        arr[i] = arr[i-1] + arr[i-5];
    
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &num);
        printf("%lld\n", arr[num-1]);
    }
    
    return 0;
}