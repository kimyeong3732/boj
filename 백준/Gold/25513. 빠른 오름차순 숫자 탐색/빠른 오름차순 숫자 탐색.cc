#include <iostream>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;
    int count;
};

int map[5][5];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool visit[5][5][7];
queue<point> q;

int bfs(int num) {
    if(num == 7)
        return q.front().count;
    
    while(!q.empty()) {
        point node = q.front();
        q.pop();
        
        if(map[node.y][node.x] == num) {
            q = queue<point>();
            
            q.push(node);
            visit[node.y][node.x][num+1] = true;
            return bfs(num+1);
        }
        
        for(int i=0; i<4; i++) {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            
            if(nx<0 || nx>=5 || ny<0 || ny>=5 || map[ny][nx]==-1 || visit[ny][nx][num])
                continue;
            
            q.push({nx, ny, node.count+1});
            visit[ny][nx][num] = true;
        }
    }
    
    return -1;
}

int main() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> map[i][j];
        }
    }
    
    int x, y;
    cin >> y >> x;
    
    q.push({x, y, 0});
    visit[y][x][1] = true;
    
    cout << bfs(1);
    
    return 0;
}