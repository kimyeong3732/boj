#include <iostream>
#include <queue>

using namespace std;

int check[1024];

int main() {
    for(int i=0; i<1024; i++)
        check[i] = -1;
    
    int is, ds;
    
    cin >> is >> ds;
    
    int num = 0;
    int d = 0;
    int digit = 1;
    
    while(is > 0) {
        num += (is % 10) * digit;
        is /= 10;
        digit *= 2;
    }
    
    digit = 1;
    
    while(ds > 0) {
        d += (ds % 10) * digit;
        ds /= 10;
        digit *= 2;
    }
    
    check[num] = 0;
    
    queue<int> q;
    
    q.push(num);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        if(node == d)
            break;
        
        for(int i=1; i<=node/2; i*=2) {
            int next = node ^ i;
            
            if(check[next] < 0) {
                check[next] = check[node] + 1;
                q.push(next);
            }
        }
        
        if(node>0 && check[node-1]<0) {
            check[node-1] = check[node] + 1;
            q.push(node-1);
        }
        
        if(node<1023 && check[node+1]<0) {
            check[node+1] = check[node] + 1;
            q.push(node+1);
        }
    }
    
    cout << check[d];
    
    return 0;
}