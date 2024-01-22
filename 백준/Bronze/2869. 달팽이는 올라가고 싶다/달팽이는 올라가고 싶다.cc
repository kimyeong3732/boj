#include <cstdio>

int main() {
    int a, b, v, day;
    
    scanf("%d%d%d", &a, &b, &v);
    
    v = v - a;
    day = 1;
    
    day += v / (a-b);
    if((v % (a-b)) != 0)
        day++;
    
    printf("%d\n", day);
    
    return 0;
}