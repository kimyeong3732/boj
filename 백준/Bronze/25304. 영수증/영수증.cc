#include <cstdio>

int main() {
    int price, sum = 0;
    int t;
    int a, n;
    
    scanf("%d%d", &price, &t);
    
    for(int i=0; i<t; i++) {
        scanf("%d%d", &a, &n);
        sum += a * n;
    }
    
    if(sum == price)
        printf("Yes\n");
    else
        printf("No\n");
    
    return 0;
}