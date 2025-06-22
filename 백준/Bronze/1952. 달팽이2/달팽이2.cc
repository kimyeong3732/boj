#include <iostream>

using namespace std;

int map[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int result = 0;
    int d = 0;
    int m, n;
    int x=0, y=0;
    
    cin >> m >> n;
    
    while(true) {
        map[y][x] = 1;
        
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if(nx<0 || nx>=n || ny<0 || ny>=m || map[ny][nx]!=0) {
            d = (d + 1) % 4;
            
            nx = x + dx[d];
            ny = y + dy[d];
        
            if(nx<0 || nx>=n || ny<0 || ny>=m || map[ny][nx]!=0)
                break;
            
            result++;
        }
        
        x += dx[d];
        y += dy[d];
    }
    
    cout << result;
    
    return 0;
}