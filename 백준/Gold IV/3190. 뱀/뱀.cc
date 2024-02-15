#include <cstdio>
#include <queue>

using namespace std;

struct dir{
    int t;
    char dir;
};

struct position {
    int x;
    int y;
};

int n, t = 0;
int map[100][100];
bool state = false;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<dir> q;
queue<position> qp;

void find() {
    int x = 0;
    int y = 0;
    int cur_dir = 0;
    qp.push({0, 0});
    
    while(!state) {
        int tt = 0;
        char dir;
        if(!q.empty()) {
            tt = q.front().t;
            dir = q.front().dir;
            q.pop();
        }
        
        if(tt == 0) {
            while(true) {
                t++;
                int nx = x + dx[cur_dir];
                int ny = y + dy[cur_dir];
                
                if(nx<0 || nx>=n || ny<0 || ny>=n || map[ny][nx]==2) {
                    state = true;
                    break;
                }
                
                if(map[ny][nx] == 0) {
                    int d_x = qp.front().x;
                    int d_y = qp.front().y;
                    qp.pop();
                    
                    map[d_y][d_x] = 0;
                }
                
                map[ny][nx] = 2;
                qp.push({nx, ny});
                
                x = nx;
                y = ny;
            }
        }
        else {
            while(t < tt) {
                t++;
                int nx = x + dx[cur_dir];
                int ny = y + dy[cur_dir];
                
                if(nx<0 || nx>=n || ny<0 || ny>=n || map[ny][nx]==2) {
                    state = true;
                    break;
                }
                
                if(map[ny][nx] == 0) {
                    int d_x = qp.front().x;
                    int d_y = qp.front().y;
                    qp.pop();
                    
                    map[d_y][d_x] = 0;
                }
                
                map[ny][nx] = 2;
                qp.push({nx, ny});
                
                x = nx;
                y = ny;
            }
            if(dir == 'D')
                cur_dir = (cur_dir + 1) % 4;
            else
                cur_dir = (cur_dir + 3) % 4;
        }
    }
}

int main() {
    int k, l;
    scanf("%d", &n);
    scanf("%d", &k);
    
    for(int i=0; i<k; i++) {
        int x, y;
        scanf("%d%d", &y, &x);
        
        map[y-1][x-1] = 1;
    }
    map[0][0] = 2;
    
    scanf("%d", &l);
    
    for(int i=0; i<l; i++) {
        int tt;
        char dir[2];
        scanf("%d", &tt);
        scanf("%s", dir);
        
        q.push({tt, dir[0]});
    }
    
    find();
    
    printf("%d\n", t);
    
    return 0;
}
