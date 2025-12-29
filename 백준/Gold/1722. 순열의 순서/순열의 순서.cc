#include <iostream>

using namespace std;

long long fact[20];
bool visit[21];

int main() {
    int n, p;
    
    cin >> n >> p;
    
    fact[0] = 1;
    
    for(int i=1; i<n; i++)
        fact[i] = i * fact[i-1];
    
    if(p == 1) {
        long long k;
        
        cin >> k;
        
        for(int i=n-1; i>=0; i--) {
            for(int j=1; j<=n; j++) {
                if(!visit[j]) {
                    if(fact[i] < k) {
                        k -= fact[i];
                    }
                    
                    else {
                        cout << j << " ";
                        visit[j] = true;
                        break;
                    }
                }
            }
        }
    }
    
    else {
        int num;
        long long k = 0;
        
        for(int i=n-1; i>=0; i--) {
            cin >> num;
            
            for(int j=1; j<num; j++)
                if(!visit[j])
                    k += fact[i];
            
            visit[num] = true;
        }
        
        cout << k+1;
    }
    
    return 0;
}