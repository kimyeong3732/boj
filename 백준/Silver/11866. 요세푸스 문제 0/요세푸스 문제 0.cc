#include <cstdio>

int main() {
    int n, k, count = 0, count2 = 0;
    int index = 0;
    int *arr;
    
    scanf("%d%d", &n, &k);
    
    arr = new int[n];
    for(int i=0; i<n; i++)
        arr[i] = 1;
    
    printf("<");
    while(count < n) {
        if(arr[index] == 1) {
            count2++;
            if(count2 == k) {
                if(count != 0)
                    printf(", ");
                count++;
                count2 = 0;
                arr[index] = 0;
                printf("%d", index+1);
            }
        }
        index = (index+1) % n;
    }
    printf(">\n");
    
    return 0;
}