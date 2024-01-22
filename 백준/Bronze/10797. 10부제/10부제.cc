#include <cstdio>

int main() {
    int num;
    int result = 0;
    
    scanf("%d", &num);
    
    for(int i=0; i<5; i++) {
        int temp;
        
        scanf("%d", &temp);
        
        if(num == temp)
            result++;
    }
    
    printf("%d\n", result);
    
    return 0;
}