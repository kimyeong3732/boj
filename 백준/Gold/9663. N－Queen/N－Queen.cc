#include <cstdio>
#include <algorithm>
using namespace std;

int cnt = 0;
int arr[15][15] = { 0 };

void find(int n, int r) {
    if(r == n) {
        cnt++;
        return;
    }
    
    for(int i=0; i<n; i++) {
        int state = 0;
        
        for(int j=0; j<r; j++) {
            int a = i - (r - j);
            int b = i + (r - j);
            
            if(((arr[j][a]==1) && (a>=0)) || ((arr[j][b]==1) && (b<n)) || (arr[j][i]==1)) {
                state = 1;
                break;
            }
        }
        
        if(state == 0) {
            arr[r][i] = 1;
            find(n, r+1);
            arr[r][i] = 0;
        }
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    find(n, 0);
    
    printf("%d\n", cnt);
    
    return 0;
}