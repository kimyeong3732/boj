#include <cstdio>

int main() {
    int n;
    int num2 = 0, num5 = 0;
    
    scanf("%d", &n);
    
    for(int i=2; i<=n; i++) {
        for(int j=i; j>0; j/=2) {
            if((j%2) == 0)
                num2++;
            else
                break;
        }
        
        for(int j=i; j>0; j/=5) {
            if((j%5) == 0)
                num5++;
            else
                break;
        }
    }
    if(num2 >= num5)
        printf("%d\n", num5);
    else
        printf("%d\n", num2);
    
    return 0;
}