#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if(abs(a) > abs(b))
            return true;
        else if(abs(a) == abs(b)) {
            if(a > b)
                return true;
            return false;
        }
        return false;
    }
};

int main() {
    int n;
    priority_queue<int, vector<int>, cmp> q;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int num;
        
        scanf("%d", &num);
        
        if(num != 0)
            q.push(num);
        else {
            if(q.empty())
                printf("0\n");
            else {
                printf("%d\n", q.top());
                q.pop();
            }
        }
    }
    
    return 0;
}