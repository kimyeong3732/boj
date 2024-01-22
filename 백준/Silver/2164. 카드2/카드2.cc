#include <cstdio>

int main() {
    int n, arr[500000];
    int count = 0, index = 0, state = 0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        arr[i] = 1;
    
    while(count < (n-1)) {
        if(arr[index] == 0) {
            index = (index+1) % n;
        }
        
        else {
            if(state == 0)
                arr[index] = 0;
            else
                count++;
            state = (state+1) % 2;
            index = (index+1) % n;
        }
    }
    
    for(int i=0; i<n; i++) {
        if(arr[i] == 1) {
            printf("%d\n", i+1);
            break;
        }
    }
    
    return 0;
}