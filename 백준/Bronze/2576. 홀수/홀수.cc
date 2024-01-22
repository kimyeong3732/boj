#include <cstdio>

int main() {
    int result = -1;
    int sum = 0;
    
    for(int i=0; i<7; i++) {
        int num;
        
        scanf("%d", &num);
        
        if((num%2) == 1) {
            if(sum == 0)
                result = num;
            else if(result > num)
                result = num;
            sum += num;
        }
    }
    
    if(result != -1)
        printf("%d\n", sum);
    printf("%d\n", result);
    
    return 0;
}