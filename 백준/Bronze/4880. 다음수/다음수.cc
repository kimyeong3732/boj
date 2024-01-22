#include <cstdio>

int main() {
    int a = 1, b = 1, c = 1;
    
    while(1) {
        scanf("%d%d%d", &a, &b, &c);
        
        if((a==0) && (b==0) && (c==0))
            break;
        
        int ap = b - a;
        int gp = b / a;
        
        if((c-b) == ap)
            printf("AP %d\n", c+ap);
        else
            printf("GP %d\n", c*gp);
    }
    
    return 0;
}