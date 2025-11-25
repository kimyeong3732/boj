#include <iostream>

using namespace std;

int n, m;
int map[500][500];
int dp[500][500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y) {
    if(x==m-1 && y==n-1)
        return 1;
    
    if(dp[y][x] != -1)
        return dp[y][x];
    
    dp[y][x] = 0;
    
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<m && ny>=0 && ny<n && map[y][x]>map[ny][nx])
            dp[y][x] += dfs(nx, ny);
    }
    
    return dp[y][x];
}

int main() {
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            
            dp[i][j] = -1;
        }
    }
    
    cout << dfs(0, 0);
    
    return 0;
}