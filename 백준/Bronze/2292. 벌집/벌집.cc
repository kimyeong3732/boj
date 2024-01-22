#include <cstdio>

int main() {
    int n, i, temp = 1;
    
    scanf("%d", &n);
    
    if(n == 1)
        printf("1\n");
    else {
        for(i=1; temp<=1000000000; i++) {
            temp += 6 * i;
            if(temp >= n)
                break;
        }
        printf("%d\n", i+1);
    }
    
    return 0;
}