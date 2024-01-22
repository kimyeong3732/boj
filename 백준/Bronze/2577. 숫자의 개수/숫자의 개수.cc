#include <cstdio>

int main() {
    int a, b, c;
    int mul, arr[10];
    
    for(int i=0; i<10; i++) arr[i] = 0;
    
    scanf("%d%d%d", &a, &b, &c);
    mul = a * b * c;
    for(mul; mul; mul=mul/10) arr[mul%10] += 1;
    
    for(int i=0; i<10; i++) printf("%d\n", arr[i]);
    
    return 0;
}