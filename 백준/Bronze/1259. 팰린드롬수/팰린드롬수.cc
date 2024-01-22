#include <cstdio>

int main() {
    int n;
    
    scanf("%d", &n);
    
    while(n != 0) {
        int temp = n, result = 0;
        for(int i=10; temp!=0; temp/=i) {
            result *= 10;
            result += temp % 10;
        }
        if(n == result) printf("yes\n");
        else printf("no\n");
        scanf("%d", &n);
    }
    
    return 0;
}