#include <iostream>
#include <queue>

using namespace std;

struct shark {
    int v = -1;
    int dir, size;
} mymap[100][100];

struct point {
    int x, y;
};

int N, M;
int result = 0;
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, -1, 1, 0, 0};
int new_dir[] = {0, 2, 1, 4, 3};
queue<point> q;

void move() {
    int qsize = q.size();
    shark copy_map[100][100];
    
    for(int i=0; i<qsize; i++) {
        int qx = q.front().x;
        int qy = q.front().y;
        q.pop();
        
        if(mymap[qy][qx].v > -1) {
            int x = qx;
            int y = qy;
            int v = mymap[y][x].v;
            int dir = mymap[y][x].dir;
            int size = mymap[y][x].size;
            
            x += dx[dir] * v;
            y += dy[dir] * v;
            
            if(dir<3 && (dir!=1 || y<=0)) {
                
                if(y < 0) {
                    y *= -1;
                }
                
                int ylot = y / (N - 1);
                int yrest = y % (N - 1);
                
                if(ylot%2 == 0) {
                    y = yrest;
                    dir = 2;
                }
                else {
                    y = N - 1 - yrest;
                    dir = 1;
                }
            }
            
            else if(dir>=3 && (dir!=4 || x<=0)){
                if(x < 0) {
                    x *= -1;
                }
                
                int xlot = x / (M - 1);
                int xrest = x % (M - 1);
                
                if(xlot%2 == 0) {
                    x = xrest;
                    dir = 3;
                }
                else {
                    x = M - 1 - xrest;
                    dir = 4;
                }
            }
            
            if(copy_map[y][x].v>-1 && copy_map[y][x].size > size) {
                continue;
            }
            
            copy_map[y][x] = {v, dir, size};
            q.push({x, y});
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            mymap[i][j] = copy_map[i][j];
        }
    }
}

void fishing(int position) {
    for(int i=0; i<N; i++) {
        if(mymap[i][position].v > -1) {
            result += mymap[i][position].size;
            mymap[i][position] = {-1, 0, 0};
            break;
        }
    }
    
    move();
}

int main() {
    int num_shark;
    
    cin >> N >> M >> num_shark;
    
    for(int i=0; i<num_shark; i++) {
        int x, y, v, d, s;
        
        cin >> y >> x >> v >> d >> s;
        
        mymap[y-1][x-1] = {v, d, s};
        q.push({x-1, y-1});
    }
    
    
    for(int i=0; i<M; i++) {
        fishing(i);
    }
    
    cout << result;
    
    return 0;
}

