#include <cstdio>
#include <cstring>

int main() {
    int n, index = 0;
    int arr[10000];
    char com[6];
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        scanf("%s", com);
        
        if(strcmp(com, "push") == 0) {
            scanf("%d", arr+index);
            index++;
        }
        else if(strcmp(com, "pop") == 0) {
            if(index > 0) {
                index--;
                printf("%d\n", arr[index]);
                arr[index]= 0;
            }
            else
                printf("-1\n");
        }
        else if(strcmp(com, "size") == 0) {
            printf("%d\n", index);
        }
        else if(strcmp(com, "empty") == 0) {
            if(index > 0)
                printf("0\n");
            else
                printf("1\n");
        }
        else {
            if(index > 0)
                printf("%d\n", arr[index-1]);
            else
                printf("-1\n");
        }
    }
    
    return 0;
}