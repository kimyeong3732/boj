#include <iostream>

using namespace std;

int n, p, d;
int s[20];
int e[20];
int result[20];
bool state = false;

void find(int node, int mn, int mx, int size) {
    if(size == p) {
        if(mn<=d && d<=mx) {
            int rest = d - mn;
            
            for(int i=0; i<n; i++) {
                if(result[i]>0 && rest>0) {
                    if(s[i]+rest <= e[i]) {
                        result[i] = s[i] + rest;
                        rest = 0;
                    }
                    
                    else {
                        result[i] = e[i];
                        rest -= e[i] - s[i];
                    }
                }
                
                cout << result[i] << " ";
            }
            
            state = true;
        }
        
        return;
    }
    
    for(int i=node; i>=p-size-1; i--) {
        result[i] = s[i];
        
        find(i-1, mn+s[i], mx+e[i], size+1);
        
        result[i] = 0;
        
        if(state)
            return;
    }
}

int main() {
    cin >> n >> p >> d;
    
    for(int i=0; i<n; i++)
        cin >> s[i] >> e[i];
    
    find(n-1, 0, 0, 0);
    
    if(!state)
        cout << -1;
    
    return 0;
}