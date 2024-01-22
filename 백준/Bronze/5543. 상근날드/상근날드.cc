#include <cstdio>

int main() {
    int b = 2000, v = 2000;
    
    for(int i=0; i<3; i++) {
        int temp;
        scanf("%d", &temp);
        
        if(temp < b)
            b = temp;
    }
    
    for(int i=0; i<2; i++) {
        int temp;
        scanf("%d", &temp);
        
        if(temp < v)
            v = temp;
    }
    
    printf("%d\n", b+v-50);
    
    return 0;
}