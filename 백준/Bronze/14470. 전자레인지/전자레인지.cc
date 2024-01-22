#include <cstdio>

int main() {
    int a, b, c, d, e;
    int time = 0;
    
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    
    if((a<0) && (b<=0))
        time = (b - a) * c;
    
    else if((a<0) && (b>0))
        time = (0 - a) * c + d + b * e;
    
    else if((a==0) && (b>0))
        time = d + b * e;
    
    else if((a>0) && (b>0))
        time = (b - a) * e;
    
    printf("%d\n", time);
    
    return 0;
}