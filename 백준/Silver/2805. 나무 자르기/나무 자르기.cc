#include <cstdio>

int main() {
    int n, m, max = 0;
    int arr[1000000];
    
    scanf("%d%d", &n, &m);
    
    for(int i=0; i<n; i++) {
        scanf("%d", arr+i);
        if(max < arr[i])
            max = arr[i];
    }
    
    int left = 0, right = max;
    int result;
    
    while(left <= right) {
        int mid = (left+right) / 2;
        unsigned int tempM = 0;
        for(int i=0; i<n; i++) {
            if(tempM > m)
                break;
            if(arr[i] > mid)
                tempM += arr[i] - mid;
        }
        if(tempM > m) {
            left = mid + 1;
            result = mid;
        }
        else if(tempM < m)
            right = mid - 1;
        else {
            result = mid;
            break;
        }
    }
    
    
    printf("%d\n", result);
    
    return 0;
}