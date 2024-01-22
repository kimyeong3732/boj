#include <cstdio>

int main() {
    int n;
    int state = 0;
    
    scanf("%d", &n);
    
    while(n > 1) {
        if((n%2) != 0) {
            state = 1;
            break;
        }
        n /= 2;
    }
    
    if(state == 0)
        printf("1\n");
    else
        printf("0\n");
    
    return 0;
}