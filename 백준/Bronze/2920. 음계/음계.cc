#include <cstdio>

int main() {
    int i =0 , j = 0;
    int array[8];
    
    for(int k=0; k<8; k++)
        scanf("%d", array+k);
    
    for(i; i<7; i++)
        if(array[i] > array[i+1])
            break;
    
    for(j; j<7; j++)
        if(array[j] < array[j+1])
            break;
    
    if(i == 7) printf("ascending\n");
    else if(j == 7) printf("descending\n");
    else printf("mixed\n");
    
    return 0;
}