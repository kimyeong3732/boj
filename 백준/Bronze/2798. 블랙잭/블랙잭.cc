#include <cstdio>

int main() {
    int n, num, max = 0;
    int arr[100];
    
    scanf("%d%d", &n, &num);
    
    for(int i=0; i<n; i++)
        scanf("%d", arr+i);
    
    for(int i=0; i<n-2; i++)
        for(int j=i+1; j<n-1; j++)
            for(int k=j+1; k<n; k++)
                if((max<(arr[i]+arr[j]+arr[k])) && (num>=(arr[i]+arr[j]+arr[k])))
                    max = arr[i] + arr[j] + arr[k];
    
    printf("%d\n", max);
    
    return 0;
}