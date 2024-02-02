#include <cstdio>
#include <queue>

using namespace std;

struct positon {
    int rx;
    int ry;
    int bx;
    int by;
    int dir;
    int count;
};

int n, m;
char map[10][11];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<positon> q;
bool state = false;

void BFS() {
    while(!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int dir = q.front().dir;
        int c = q.front().count;
        q.pop();
        
        if(c == 10) {
            printf("-1\n");
            return;
        }
        
        if(dir < 0) {
            for(int i=0; i<4; i++) {
                int nrx = rx + dx[i];
                int nry = ry + dy[i];
                int nbx = bx + dx[i];
                int nby = by + dy[i];
                
                while(!(nrx==nbx-dx[i] && nry==nby-dy[i]) && map[nry][nrx]!='#') {
                    if(map[nry][nrx] == 'O') {
                        state = true;
                        break;
                    }
                    nrx += dx[i];
                    nry += dy[i];
                }
                
                while((!(nbx==nrx-dx[i] && nby==nry-dy[i]) || (state && nbx==nrx-dx[i] && nby==nry-dy[i]) ) && map[nby][nbx]!='#') {
                    if(map[nby][nbx] == 'O') {
                        state = false;
                        break;
                    }
                    nbx += dx[i];
                    nby += dy[i];
                    if(state && nbx==nrx-dx[i] && nby==nry-dy[i]) {
                        state = false;
                        nbx += dx[i];
                        nby += dy[i];
                        break;
                    }
                }
                
                if(map[nby][nbx] == 'O')
                    continue;
                
                while(!(nrx==nbx-dx[i] && nry==nby-dy[i]) && map[nry][nrx]!='#') {
                    if(map[nry][nrx] == 'O') {
                        printf("%d\n", c+1);
                        return;
                    }
                    nrx += dx[i];
                    nry += dy[i];
                }
                
                if(!(nrx-dx[i]==rx && nry-dy[i]==ry && nbx-dx[i]==bx && nby-dy[i]==by))
                    q.push({nrx-dx[i], nry-dy[i], nbx-dx[i], nby-dy[i], i/2*2, c+1});
            }
        }
        
        else {
            dir = (dir+2) % 4;
            for(int i=dir; i<dir+2; i++) {
                int nrx = rx + dx[i];
                int nry = ry + dy[i];
                int nbx = bx + dx[i];
                int nby = by + dy[i];
                
                while(!(nrx==nbx-dx[i] && nry==nby-dy[i]) && map[nry][nrx]!='#') {
                    if(map[nry][nrx] == 'O') {
                        state = true;
                        break;
                    }
                    nrx += dx[i];
                    nry += dy[i];
                }
                
                while((!(nbx==nrx-dx[i] && nby==nry-dy[i]) || (state && nbx==nrx-dx[i] && nby==nry-dy[i]) ) && map[nby][nbx]!='#') {
                    if(map[nby][nbx] == 'O') {
                        state = false;
                        break;
                    }
                    nbx += dx[i];
                    nby += dy[i];
                    if(state && nbx==nrx-dx[i] && nby==nry-dy[i]) {
                        state = false;
                        nbx += dx[i];
                        nby += dy[i];
                        break;
                    }
                }
                
                if(map[nby][nbx] == 'O')
                    continue;
                
                while(!(nrx==nbx-dx[i] && nry==nby-dy[i]) && map[nry][nrx]!='#') {
                    if(map[nry][nrx] == 'O' || state) {
                        printf("%d\n", c+1);
                        return;
                    }
                    nrx += dx[i];
                    nry += dy[i];
                }
                
                if(!(nrx-dx[i]==rx && nry-dy[i]==ry && nbx-dx[i]==bx && nby-dy[i]==by))
                    q.push({nrx-dx[i], nry-dy[i], nbx-dx[i], nby-dy[i], dir, c+1});
            }
        }
    }
    printf("-1\n");
}

int main() {
    scanf("%d%d", &n, &m);
    
    for(int i=0; i<n; i++) {
        scanf("%s", map[i]);
    }
    
    int rx, ry, bx, by;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 'R') {
                rx = j;
                ry = i;
            }
            if(map[i][j] == 'B') {
                bx = j;
                by = i;
            }
        }
    }
    
    q.push({rx, ry, bx, by, -1, 0});
    
    BFS();
    
    return 0;
}