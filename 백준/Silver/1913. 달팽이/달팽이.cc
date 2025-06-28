#include <iostream>

using namespace std;

int map[999][999];

int main() {
    int n, num;
    
    cin >> n >> num;
    
    int now = n * n;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int d = 0;
    int x=0, y=0;
    int rx, ry;
    
    while(now > 0) {
        map[y][x] = now;
        
        if(now == num) {
            rx = x;
            ry = y;
        }
        
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if(nx<0 || nx>=n || ny<0 || ny>=n || map[ny][nx]!=0) {
            d = (d + 1) % 4;
        }
        
        x = x + dx[d];
        y = y + dy[d];
        now--;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << ry+1 << " " << rx+1;
    
    return 0;
}