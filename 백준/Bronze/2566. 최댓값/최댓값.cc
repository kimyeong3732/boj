#include <cstdio>

int main() {
    int m = -1;
    int r, c;
    
    for(int i=1; i<10; i++) {
        for(int j=1; j<10; j++) {
            int num;
            
            scanf("%d", &num);
            
            if(m < num) {
                m = num;
                r = i;
                c = j;
            }
        }
    }
    
    printf("%d\n", m);
    printf("%d %d\n", r, c);
    
    return 0;
}