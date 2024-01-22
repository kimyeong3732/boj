#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int arr[1000];
    int sum = 0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    
    sort(arr, arr+n);
    
    for(int i=1; i<n; i++)
        arr[i] += arr[i-1];

    for(int i=0; i<n; i++) 
        sum += arr[i];
    
    printf("%d\n", sum);
    
    return 0;
}