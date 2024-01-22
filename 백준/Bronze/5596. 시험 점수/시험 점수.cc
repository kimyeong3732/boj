#include <cstdio>

int main() {
    int s = 0;
    int t = 0;
    
    for(int i=0; i<2; i++) {
        for(int j=0; j<4; j++) {
            int temp;
            scanf("%d", &temp);
            if(i == 0)
                s += temp;
            else
                t += temp;
            
        }
    }
    
    if(s >= t)
        printf("%d\n", s);
    else
        printf("%d\n", t);
    
    return 0;
}