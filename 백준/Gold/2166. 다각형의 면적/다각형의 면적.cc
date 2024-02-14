#include <cstdio>
#include <cstdlib>

int main() {
    int n;
    
    scanf("%d", &n);
    
    long long x[n], y[n];
    
    for(int i=0; i<n; i++)
        scanf("%lld%lld", x+i, y+i);
        
    long long sum = 0;
    for(int i=0; i<n; i++) {
        sum += x[i] * y[(i+1)%n];
        sum -= x[(i+1)%n] * y[i];
    }
    
    if(sum < 0)
        sum *= -1;
    
    double result = (double) sum / 2;
    
    printf("%.1f\n", result);
    
    return 0;
}