#include <cstdio>

int main() {
    int input[4], min;
    
    for(int i=0; i<4; i++) scanf("%d", input+i);
    
    input[2] = input[2] - input[0];
    input[3] = input[3] - input[1];
    
    min = input[3];
    for(int i=0; i<3; i++)
        if(min > input[i])
            min = input[i];
    
    printf("%d\n", min);
    
    return 0;
}