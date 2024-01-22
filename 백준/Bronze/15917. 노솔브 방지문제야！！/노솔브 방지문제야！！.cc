#include <cstdio>

int main() {
    int n;
    int num;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        scanf("%d", &num);
        
        while(num > 1) {
            if((num%2) == 1)
                break;
            num /= 2;
        }
        
        if(num == 1)
            printf("1\n");
        else
            printf("0\n");
    }
    
    return 0;
}