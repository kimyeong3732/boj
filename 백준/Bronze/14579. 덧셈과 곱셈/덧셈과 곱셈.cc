#include <cstdio>

int main() {
    int a, b;
    int result = 1;
    
    scanf("%d%d", &a, &b);
    
    for(int i=a; i<=b; i++) {
        int temp = 0;
        for(int j=1; j<=i; j++) {
            temp += result * j;
            if(temp >= 14579)
                temp %= 14579;
        }
        result = temp;
    }
    
    printf("%d\n", result);
    
    return 0;
}