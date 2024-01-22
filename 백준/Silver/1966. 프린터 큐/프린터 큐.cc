#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    
    for(int i=0; i<a; i++) {
        int n, m;
        int arr[100], arr2[100];
        
        scanf("%d%d", &n, &m);
        
        for(int j=0; j<n; j++) {
            scanf("%d", arr+j);
            arr2[j] = arr[j];
        }
        sort(arr2, arr2+n);
        
        int count = 0, index = 0;
        while(count < n) {
            if(arr[index] == arr2[n-1-count]) {
                count++;
                arr[index] = 0;
                if(index == m) {
                    printf("%d\n", count);
                    break;
                }
            }
            index = (index+1) % n;
        }
    }
    
    return 0;
}