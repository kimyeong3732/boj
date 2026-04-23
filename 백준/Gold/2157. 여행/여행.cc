#include <iostream>

using namespace std;

int edges[301][301];
int dp[301][301];

int main() {
    int n, m, k;
    
    cin >> n >> m >> k;
    
    for(int i=0; i<k; i++) {
        int a, b, c;
        
        cin >> a >> b >> c;
        
        if(a < b)
            edges[a][b] = max(edges[a][b], c);
    }
    
    for(int i=2; i<=n; i++)
        dp[i][2] = edges[1][i];
    
    for(int l=2; l<m; l++)
        for(int i=2; i<=n; i++)
            if(dp[i][l] != 0)
                for(int j=i+1; j<=n; j++)
                    if(edges[i][j] > 0)
                        dp[j][l+1] = max(dp[j][l+1], dp[i][l]+edges[i][j]);
    
    int result = 0;
    
    for(int i=2; i<=m; i++)
        result = max(result, dp[n][i]);
    
    cout << result;
    
    return 0;
}