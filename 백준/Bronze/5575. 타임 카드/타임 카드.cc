#include <cstdio>

int main() {
    for(int i=0; i<3; i++) {
        int time[2] = {0, 0};
        int work;
        int h, m, s;
        
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) {
                int temp;
                
                scanf("%d", &temp);
                
                time[j] *= 60;
                time[j] += temp;
            }
        }
        
        work = time[1] - time[0];
        
        h = work / 3600;
        work %= 3600;
        
        m = work / 60;
        
        s = work % 60;
        
        printf("%d %d %d\n", h, m, s);
    }
    
    return 0;
}