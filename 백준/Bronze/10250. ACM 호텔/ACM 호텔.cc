#include <cstdio>

int main() {
    int t;
    int h, w, n;
    
    scanf("%d", &t);
    
    for(int i=0; i<t; i++) {
        int room;
        scanf("%d%d%d", &h, &w, &n);
        
        if((n%h) != 0)
            room = (n%h)*100 + (n/h+1);
        else 
            room = h*100 + n/h;
        
        printf("%d\n", room);
    }
    
    return 0;
}