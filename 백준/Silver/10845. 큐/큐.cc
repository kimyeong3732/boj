#include <cstdio>
#include <cstring>

int main() {
    int n, front = 0, back = 0;
    int arr[10000];
    char com[6];
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        scanf("%s", com);
        
        if(strcmp(com, "push") == 0) {
            scanf("%d", arr+back);
            back = (back+1) % 10000;
        }
        else if(strcmp(com, "pop") == 0) {
            if(front != back) {
                printf("%d\n", arr[front]);
                arr[front]= 0;
                front = (front+1) % 10000;
            }
            else
                printf("-1\n");
        }
        else if(strcmp(com, "size") == 0) {
            int size = back - front;
            if(size < 0)
                size += 10000;
            printf("%d\n", size);
        }
        else if(strcmp(com, "empty") == 0) {
            if(front != back)
                printf("0\n");
            else
                printf("1\n");
        }
        else if(strcmp(com, "front") == 0) {
            if(front != back)
                printf("%d\n", arr[front]);
            else
                printf("-1\n");
        }
        else {
            if(front != back)
                printf("%d\n", arr[back-1]);
            else
                printf("-1\n");
        }
    }
    
    return 0;
}