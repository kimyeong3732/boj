#include <cstdio>

int main() {
    int n, count, state = 0;
    
    scanf("%d", &n);
    
    count = n / 5;
    
    if((n%5) != 0) {
        int num = n % 5;
        if((num%3) != 0) {
            for(int i=0; i<2; i++) {
                if(count > 0) {
                    count--;
                    num += 5;
                }
                if((num%3) == 0)
                    break;
            }
        }
        count += num / 3;
        if((num%3) != 0)
            state = 1;
    }
    
    if(state == 1)
        printf("-1\n");
    else
        printf("%d\n", count);
    
    return 0;
}