#include <cstdio>

int main() {
    int a, b;
    
    scanf("%d", &a);
    scanf("%d", &b);
    
    a = a / 100 * 100;
    
    for(int i=0; i<100; i++) {
        if((a+i)%b == 0) {
            printf("%02d", (a+i)%100);
            break;
        }
    }
    
    return 0;
}