#include <cstdio>
#include <queue>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int>> q;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int temp;
        scanf("%d", &temp);
        
        if(temp == 0) {
            if(q.empty())
                printf("0\n");
            else {
                printf("%d\n", q.top());
                q.pop();
            }
        }
        else
            q.push(temp);
    }
    
    return 0;
}