#include <cstdio>

int main() {
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    int axis = 0;
    
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int a, b;
        
        scanf("%d%d", &a, &b);
        if((a==0) || (b==0))
            axis++;
        else if((a>0) && (b>0))
            q1++;
        else if((a<0) && (b>0))
            q2++;
        else if((a<0) && (b<0))
            q3++;
        else
            q4++;
    }
    
    printf("Q1: %d\n", q1);
    printf("Q2: %d\n", q2);
    printf("Q3: %d\n", q3);
    printf("Q4: %d\n", q4);
    printf("AXIS: %d\n", axis);
    
    return 0;
}