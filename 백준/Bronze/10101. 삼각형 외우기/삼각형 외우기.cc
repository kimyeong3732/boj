#include <cstdio>

int main() {
    int a, b, c;
    int sum;
    
    scanf("%d%d%d", &a, &b, &c);
    
    sum = a + b + c;
    if(sum == 180) {
        if((a==60) && (b==60) && (c==60))
            printf("Equilateral\n");
        else if((a==b) || (b==c) || (a==c))
            printf("Isosceles\n");
        else
            printf("Scalene\n");
    }
    else
        printf("Error\n");
    
    return 0;
}