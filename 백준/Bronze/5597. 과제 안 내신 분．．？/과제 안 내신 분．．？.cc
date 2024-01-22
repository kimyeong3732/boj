#include <cstdio>

int main() {
    int student[30];
    
    for(int i=0; i<30; i++) student[i] = 0;
    
    for(int i=0; i<28; i++) {
        int temp;
        scanf("%d", &temp);
        student[temp-1] = 1;
    }
    
    for(int i=0; i<30; i++)
        if(student[i] == 0)
            printf("%d\n", i+1);
    
    return 0;
}