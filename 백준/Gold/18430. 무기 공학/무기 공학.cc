#include <iostream>

using namespace std;

int n, m;
int map[5][5];
bool visit[5][5];
int dx[] = {-1, 0, 1, 0, 1, 0, -1, 0};
int dy[] = {0, -1, 0, -1, 0, 1, 0, 1};

int dfs(int x, int y) {
    if(x == m) {
        x = 0;
        y++;
    }
    
    if(y == n)
        return 0;
    
    int result = 0;
    
    if(!visit[y][x]) {
        for(int i=0; i<4; i++) {
            int nx1 = x + dx[i*2];
            int ny1 = y + dy[i*2];
            int nx2 = x + dx[i*2+1];
            int ny2 = y + dy[i*2+1];
            
            if(nx1<0 || nx1>=m || nx2<0 || nx2>=m || ny1<0 || ny1>=n || ny2<0 || ny2>=n || visit[ny1][nx1] || visit[ny2][nx2])
                continue;
            
            visit[y][x] = true;
            visit[ny1][nx1] = true;
            visit[ny2][nx2] = true;
            
            int temp = map[y][x]*2 + map[ny1][nx1] + map[ny2][nx2];
            
            result = max(result, dfs(x+1, y)+temp);
            
            visit[y][x] = false;
            visit[ny1][nx1] = false;
            visit[ny2][nx2] = false;
        }
    }
    
    result = max(result, dfs(x+1, y));
    
    return result;
}

int main() {
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> map[i][j];
    
    cout << dfs(0, 0);
    
    return 0;
}