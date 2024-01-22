#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    int arr[500000];
    
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    
    sort(arr, arr+n);
    
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        int temp;
        scanf("%d", &temp);
        
        int *low, *high;
        
        low = lower_bound(arr, arr+n, temp);
        high = upper_bound(arr, arr+n, temp);
        
        printf("%d ", high-low);
    }
    
    printf("\n");
    
    return 0;
}