#include <iostream>
#include <algorithm>

using namespace std;

int p[50];
bool y[10000];

int main() {
    int n, m;
    int c[50], w[10000];
    
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> c[i];
    
    cin >> m;
    for(int i=0; i<m; i++)
        cin >> w[i];
    
    sort(c, c+n, greater<int>());
    sort(w, w+m, greater<int>());
    
    if(c[0] < w[0]) {
        cout << -1;
    }
    
    else {
        int count = 0;
        int result = 0;
        
        while(count < m) {
            for(int i=0; i<n; i++) {
                for(int j=p[i]; j<m; j++) {
                    p[i]++;
                    
                    if(!y[j] && c[i]>=w[j]) {
                        y[j] = true;
                        count++;
                        break;
                    }
                }
            }
            
            result++;
        }
        
        cout << result;
    }
    
    return 0;
}