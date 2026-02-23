#include <iostream>

using namespace std;

bool check[360];

int main() {
    int n, k;
    
    cin >> n >> k;
    
    for(int i=0; i<n; i++) {
        int a;
        
        cin >> a;
        
        int t = 0;
        
        while(true) {
            check[t] = true;
            
            for(int j=0; j<360; j++) {
                if(check[j]) {
                    check[(j+t) % 360] = true;
                    check[abs(j-t)] = true;
                }
            }
            
            t = (t+a) % 360;
            
            if(t == 0)
                break;
        }
    }
    
    for(int i=0; i<k; i++) {
        int b;
        
        cin >> b;
        
        if(check[b])
            cout << "YES\n";
        
        else
            cout << "NO\n";
    }
    
    return 0;
}