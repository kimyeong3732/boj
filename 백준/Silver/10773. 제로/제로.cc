#include <cstdio>

int main() {
    int k, index = 0, sum = 0;
    int arr[100000];
    
    scanf("%d", &k);
    
    for(int i=0; i<k; i++) {
        int temp;
        scanf("%d", &temp);
        
        if(temp == 0) {
            index--;
            arr[index] = 0;
        }
        else {
            arr[index] = temp;
            index++;
        }
    }
    
    for(int i=0; i<index; i++)
        sum += arr[i];
    
    printf("%d\n", sum);
    
    return 0;
}