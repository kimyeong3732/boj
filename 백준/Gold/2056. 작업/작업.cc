#include <iostream>

using namespace std;

int dp[10001];

int main() {
    int n;
    
    cin >> n;
    
    int result = 0;
    
    for(int i=1; i<=n; i++) {
        int t, o;
        
        cin >> t >> o;
        
        if(o != 0) {
            for(int j=0; j<o; j++) {
                int c;
                
                cin >> c;
                
                dp[i] = max(dp[i], dp[c]);
            }
        }
        
        dp[i] += t;
        
        result = max(result, dp[i]);
    }
    
    cout << result;
    
    return 0;
}