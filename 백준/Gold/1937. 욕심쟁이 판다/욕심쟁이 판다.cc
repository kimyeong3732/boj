#include <iostream>

using namespace std;

int n;
int map[500][500];
int dp[500][500];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int find(int y, int x) {
    if(dp[y][x] != 0)
        return dp[y][x];
    
    dp[y][x] = 1;
    
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx<0 || nx>=n || ny<0 || ny>=n || map[ny][nx]<=map[y][x])
            continue;
        
        dp[y][x] = max(dp[y][x], find(ny, nx)+1);
    }
    
    return dp[y][x];
}

int main() {
    cin >> n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> map[i][j];
    
    int result = 0;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            result = max(result, find(i, j));
    
    cout << result;
    
    return 0;
}