#include <cstdio>

int cal(int n, bool mode) {
    if(n == 1)
        return 1;
        
    if(!mode)
        return cal(n-1, false) * 2 + 1;
    
    if(n == 2)
        return 3;
    return cal(n-2, false) + 3 + cal(n-2, true);
}

void hanoi(int n, char from, char to, char other, bool mode) {
    if(!mode) {
        if(n == 1)
            printf("%c %c\n", from, to);
        else {
            hanoi(n-1, from, other, to, false);
            printf("%c %c\n", from, to);
            hanoi(n-1, other, to, from, false);
        }
    }
    else {
        if(n == 1)
            printf("%c D\n", from);
        else if(n == 2) {
            printf("%c %c\n", from, to);
            printf("%c D\n", from);
            printf("%c D\n", to);
        }
        else {
            hanoi(n-2, from, other, to, false);
            printf("%c %c\n", from, to);
            printf("%c D\n", from);
            printf("%c D\n", to);
            hanoi(n-2, other, to, from, true);
        }
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    printf("%d\n", cal(n, true));
    
    hanoi(n, 'A', 'B', 'C', true);
    
    return 0;
}