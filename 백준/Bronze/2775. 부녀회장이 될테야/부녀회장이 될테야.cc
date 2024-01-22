#include <cstdio>

int main() {
    int T;
    int people[15][14];
    
    for(int i=0; i<15; i++) {
        for(int j=0; j<14; j++) {
            if(i == 0)
                people[i][j] = j + 1;
            else {
                int temp = 0;
                
                for(int k=0; k<j+1; k++) {
                    temp += people[i-1][k];
                }
                people[i][j] = temp;
            }
        }
    }
    
    scanf("%d", &T);
    
    for(int i=0; i<T; i++) {
        int k, n;
        scanf("%d%d", &k, &n);
        printf("%d\n", people[k][n-1]);
    }
    
    return 0;
}