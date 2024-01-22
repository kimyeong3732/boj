#include <cstdio>

int main() {
    int n, sum = 0;
    char c[101];
    
    scanf("%d%s", &n, c);
    for(int i=0; c[i]; i++) {
        sum += c[i] - '0';
    }
    
    printf("%d\n", sum);
    
    return 0;
}