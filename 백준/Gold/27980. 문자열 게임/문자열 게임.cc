#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int al, bl;
    char a[5001], b[5001];
    
    cin >> al >> bl;
    cin >> a >> b;
    
    int dp[5002][2];
    
    for(int i=0; i<=al+1; i++) {
        dp[i][1] = 0;
    }
    dp[0][0] = 0;
    dp[al+1][0] = 0;
    
    for(int i=0; i<bl; i++) {
        char bch = b[i];
        
        for(int j=0; j<al; j++) {
            char ach = a[j];
            
            int num = ach==bch ? 1 : 0;
            
            num += max(dp[j][(i+1)%2], dp[j+2][(i+1)%2]);
            
            dp[j+1][i%2] = num;
        }
    }
    
    int result = 0;
    
    for(int i=1; i<=al; i++) {
        result = max(result, dp[i][(bl+1)%2]);
    }
    
    cout << result;
    
    return 0;
}