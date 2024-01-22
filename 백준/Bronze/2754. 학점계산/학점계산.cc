#include <cstdio>

int main() {
    char grade[3];
    float n;
    scanf("%s", grade);
    
    switch(grade[0]) {
        case 'A':
            n = 4.0;
            if(grade[1] == '+') n += 0.3;
            else if(grade[1] == '-') n -= 0.3;
            break;
        case 'B':
            n = 3.0;
            if(grade[1] == '+') n += 0.3;
            else if(grade[1] == '-') n -= 0.3;
            break;
        case 'C':
            n = 2.0;
            if(grade[1] == '+') n += 0.3;
            else if(grade[1] == '-') n -= 0.3;
            break;
        case 'D':
            n = 1.0;
            if(grade[1] == '+') n += 0.3;
            else if(grade[1] == '-') n -= 0.3;
            break;
        case 'F':
            n = 0.0;
            break;
        default:;
    }
    
    printf("%.1f\n", n);
    
    return 0;
}