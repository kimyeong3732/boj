#include <cstdio>

int main() {
    int sum = 0;
    
    while(1) {
        int temp;
        scanf("%d", &temp);
        
        if(temp == -1)
            break;
        
        sum += temp;
    }
    
    printf("%d\n", sum);
    
    return 0;
}