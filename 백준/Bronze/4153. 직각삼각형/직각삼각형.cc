#include <cstdio>

int main() {
    int a, b, c;
    
    scanf("%d%d%d", &a, &b, &c);
    
    while((a+b+c) != 0) {
        if(c>a && c>b) {
            if((a*a + b*b) == c*c)
                printf("right\n");
            else
                printf("wrong\n");
        }
        if(b>a && b>c) {
            if((a*a + c*c) == b*b)
                printf("right\n");
            else
                printf("wrong\n");
        }
        if(a>b && a>b) {
            if((b*b + c*c) == a*a)
                printf("right\n");
            else
                printf("wrong\n");
        }
        scanf("%d%d%d", &a, &b, &c);
    }
    
    return 0;
}