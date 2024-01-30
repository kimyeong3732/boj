#include <cstdio>

int r, c;
char map[20][21];
bool visit[26] = {false};
int result = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void find(int x, int y, int count) {
    if(count > result)
        result = count;
    
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<c && ny>=0 && ny<r && !visit[map[ny][nx]-'A']) {
            visit[map[ny][nx]-'A'] = true;
            find(nx, ny, count+1);
            visit[map[ny][nx]-'A'] = false;
        }
    }
}

int main() {
    scanf("%d%d", &r, &c);
    
    for(int i=0; i<r; i++) {
        scanf("%s", &map[i]);
    }
    
    visit[map[0][0]-'A'] = true;
    find(0, 0, 1);
    
    printf("%d\n", result);
    
    return 0;
}