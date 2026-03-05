#include <iostream>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;
};

int map[200][200];
int n, k, t, rx, ry;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<point, int>> q;

void find() {
    while(!q.empty()) {
        point node = q.front().first;
        int ct = q.front().second;
        q.pop();
        
        if(ct == t)
            break;
        
        for(int i=0; i<4; i++) {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=n || map[ny][nx]!=0)
                continue;
            
            map[ny][nx] = map[node.y][node.x];
            
            point temp;
            temp.x = nx;
            temp.y = ny;
            
            q.push(make_pair(temp, ct+1));
        }
    }
}

int main() {
    cin >> n >> k;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> map[i][j];
    
    cin >> t >> ry >> rx;
    
    for(int l=1; l<=k; l++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(map[i][j] == l){
                    point temp;
                    temp.x = j;
                    temp.y = i;
                    
                    q.push(make_pair(temp, 0));
                }
            }
        }
    }
    
    find();
    
    cout << map[ry-1][rx-1];
    
    return 0;
}