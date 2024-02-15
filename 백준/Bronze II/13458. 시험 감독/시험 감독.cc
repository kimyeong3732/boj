#include <cstdio>

int main() {
    int n;
    
    scanf("%d", &n);
    
    long long arr[n];
    
    for(int i=0; i<n; i++)
        scanf("%lld", arr+i);
    
    long long b, c;
    
    scanf("%lld%lld", &b, &c);
    
    long long result = 0;
    
    for(int i=0; i<n; i++) {
        int temp = arr[i];
        
        result++;
        
        if(temp > b) {
            temp -= b;
            
            result += temp / c;
            
            if(temp%c != 0)
                result++;
        }
    }
    
    printf("%lld\n", result);
    
    return 0;
}