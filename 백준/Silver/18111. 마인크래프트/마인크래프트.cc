#include <cstdio>

int main() {
    int n, m, b;
    int *arr;
    int maxHeight = 0, minHeight = 256;
    int time = 127500000, resultHeight = 0;
    
    scanf("%d%d%d", &n, &m, &b);
    arr = new int[n*m];
    
    for(int i=0; i<n*m; i++) {
        scanf("%d", arr+i);
        int j;
        
        if(arr[i] > maxHeight)
            maxHeight = arr[i];
        if(arr[i] < minHeight)
            minHeight = arr[i];
        }
    
    for(int i=maxHeight; i>=minHeight; i--) {
        int tempTime = 0;
        int tempB = b;
        for(int j=0; j<n*m; j++) {
            if(arr[j] > i) {
                tempTime += (arr[j]-i) * 2;
                tempB += arr[j] - i;
            }
            else if(arr[j] < i) {
                tempTime += i - arr[j];
                tempB -= i - arr[j];
            }
        }
        
        if(tempB >= 0) {
            if(tempTime < time) {
                time = tempTime;
                resultHeight = i;
            }
        }
    }
    
    printf("%d %d\n", time, resultHeight);
    
    return 0;
}