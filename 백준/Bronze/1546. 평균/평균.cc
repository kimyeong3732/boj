#include <cstdio>

int main() {
    int n, num;
    float max = 0, sum = 0;
    
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &num);
        if(max < num) max = num;
        sum += (float)num;
    }
    printf("%f\n", (sum*100.0)/(max*n));
    
    return 0;
}