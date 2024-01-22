#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n;
    priority_queue<int> q;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        
        if(num == 0) {
            if(!q.empty()) {
                printf("%d\n", q.top());
                q.pop();
            }
            else
                printf("0\n");
        }
        else
            q.push(num);
    }
    
    return 0;
}