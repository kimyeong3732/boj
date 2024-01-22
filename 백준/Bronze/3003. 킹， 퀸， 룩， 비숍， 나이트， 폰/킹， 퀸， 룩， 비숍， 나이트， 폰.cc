#include <cstdio>

int main() {
    int correct[] = { 1, 1, 2, 2, 2, 8 };
    int now[6];
    
    for(int i=0; i<6; i++) {
        scanf("%d", now+i);
        printf("%d ", correct[i]-now[i]);
    }
    printf("\n");
    
    return 0;
}