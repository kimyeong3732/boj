#include <cstdio>

int main() {
    int n, m;
    int array[100][100];
    
    scanf("%d%d", &n, &m);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &array[i][j]);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int temp;
            scanf("%d", &temp);
            array[i][j] += temp;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}