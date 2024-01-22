#include <cstdio>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int num = 0;
        int sum = 0;
        char c;
        
        scanf("%c", &c);
        while(c == '\n')
            scanf("%c", &c);
        
        while(c != '\n') {
            if(c == ' ') {
                sum += num;
                num = 0;
            }
            else {
                num *= 10;
                num += c - '0';
            }
            
            scanf("%c", &c);
        }
        sum += num;
        
        printf("%d\n", sum);
    }
    
    return 0;
}