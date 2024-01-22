#include <cstdio>

int main() {
    char sol[8][8] ={{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                     {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                     {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                     {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                     {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};
    
    int m, n, min = 64;
    char input[50][50];
    
    scanf("%d%d", &m, &n);
    
    for(int i=0; i<m; i++)
        scanf("%s", &input[i]);
    
    for(int i=0; i<=(m-8); i++) {
        for(int j=0; j<=(n-8); j++) {
            int count1 = 0, count2 = 0;
            for(int k=0; k<8; k++) {
                for(int l=0; l<8; l++) {
                    if(sol[k][l] != input[i+k][j+l]) count1++;
                    if(sol[7-k][l] != input[i+k][j+l]) count2++;
                }
            }
            
            if(min > count1) min = count1;
            if(min > count2) min = count2;
        }
    }
    
    printf("%d\n", min);
    
    return 0;
}