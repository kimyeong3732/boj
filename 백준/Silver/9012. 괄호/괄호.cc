#include <cstdio>

int main() {
    int n;
    char arr[51], arr2[51] = {0};
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int state = 1, index = 0;
        scanf("%s", arr);
        for (int j=0; arr[j]; j++) {
            if (arr[j] == '(') {
                arr2[index] = '(';
                index++;
            }
            else {
                if ((arr2[index-1]=='(') && (index>0)) {
                    arr2[index] = 0;
                    arr2[index-1] = 0;
                    index--;
                }
                else
                    state = 0;
            }
        }
        if ((index==0) && (state==1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}