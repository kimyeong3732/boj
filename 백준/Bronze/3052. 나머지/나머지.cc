#include <cstdio>

int main() {
    int n, arr[10];
    int size = 0;
    
    for(int i=0; i<10; i++) {
        int j = 0;
        scanf("%d", &n);
        
        n = n % 42;
        for(j; j<size; j++)
            if(arr[j] == n)
                break;
        
        if(j == size)
            arr[size++] = n;
    }
    
    printf("%d\n", size);
    
    return 0;
}