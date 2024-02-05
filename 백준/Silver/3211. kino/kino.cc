#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int arr[10000];
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    
    sort(arr, arr+n);
    
    int index = 0;
    int result = 1;
    
    while(arr[index]+1 > result) {
        result = arr[index]+1;
        index = arr[index];
    }
    
    printf("%d\n", result);
    
    return 0;
}