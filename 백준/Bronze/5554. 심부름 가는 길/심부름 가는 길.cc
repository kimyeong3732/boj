#include <cstdio>

int main() {
    int temp;
    int time = 0;
    
    for(int i=0; i<4; i++) {
        scanf("%d", &temp);
        time += temp;
    }
    
    printf("%d\n%d\n", time/60, time%60);
    
    return 0;
}