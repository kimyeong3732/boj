#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct point {
    int x, y;
};

int n, m, d;
int ori_map[15][15];
int game_map[15][15];
int dx[] = {-1, 0, 1}; // 우선순위 좌 > 상 > 우
int dy[] = {0, -1, 0};
int arch[3]; // 궁수 위치 저장 x 값만 저장
point enemy[3]; // 각 궁수가 포착한 적 위치 저장

// 남은 모든 적 한 칸 씩 아래로 이동 맨 아래줄(n-1) 에 있는 적은 삭제
void move() {
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<m; j++) {
            if(game_map[i][j] == 1) {
                if(i != n-1)
                    game_map[i+1][j] = 1;
                
                game_map[i][j] = 0;
            }
        }
    }
}

// 저장된 적 제거 후 제거한 숫자 반환
int kill() {
    int count = 0;
    
    for(int i=0; i<3; i++) {
        if(enemy[i].x!=-1 && enemy[i].y!=-1) { // 궁수가 적을 포착하지 못하면 x=-1, y=-1
            if(game_map[enemy[i].y][enemy[i].x] == 1) { // 이전 궁수가 적을 제거했는지 확인
                game_map[enemy[i].y][enemy[i].x] = 0;
                count++;
            }
        }
    }
    
    return count;
}

// 궁수와의 거리 측정
// true - 궁수가 포착하지 못함
// false - 궁수가 포착함
bool check(int ax, int ay, int bx, int by) {
    return d < abs(ax-bx)+abs(ay-by);
}

// 각 궁수가 적을 확인하는 함수
void find() {
    for(int i=0; i<3; i++) {
        queue<point> q; // bfs
        
        q.push({arch[i], n-1});
        
        bool visit[n][m];
        
        for(int j=0; j<n; j++) // visit 초기화
            for(int k=0; k<m; k++)
                visit[j][k] = false;
        
        while(!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();
            
            if(check(x, y, arch[i], n)) { // 궁수가 적을 포착하지 못하는 경우 x=-1 y=-1
                enemy[i] = {-1, -1};
                break;
            }
            
            if(game_map[y][x] == 1) { // 궁수가 가장 가까운 적을 포착한 경우
                enemy[i] = {x, y};
                break;
            }
            
            for(int j=0; j<3; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visit[ny][nx]) {
                    visit[ny][nx] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

// 맵이 비었는 지 확인
// true - 맵이 비어 있음
// false - 맵이 비어 있지 않음
bool is_clear() {
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(game_map[i][j] == 1)
                return false;
    
    return true;
}

// 게임 시작
int game() {
    int count = 0; // 한 게임동안 제거된 적 숫자
    
    while(!is_clear()) { // 맵이 비어 있지 않으면 계속 반복
        find(); // 궁수가 적을 포착하는 함수
        count += kill(); // 궁수가 적 제거 및 제거한 숫자 증가
        move(); // 모든 적 한 칸 아래로 이동
    }
    
    return count;
}

int main() {
    scanf("%d%d%d", &n, &m, &d);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &ori_map[i][j]);
            
    int result = 0;
    
    for(int i=0; i<m; i++) { // 궁수의 위치는 조합으로 지정
        arch[0] = i;
        
        for(int j=i+1; j<m; j++) {
            arch[1] = j;
            
            for(int k=j+1; k<m; k++) {
                arch[2] = k;
                
                copy(&ori_map[0][0], &ori_map[0][0]+(15*15), &game_map[0][0]); // 원본 맵을 게임용 맵으로 복사
                
                int temp = game(); // 하나의 조합으로 게임 진행
                
                if(result < temp) // 최소값 갱신
                    result = temp;
            }
        }
    }
    
    printf("%d\n", result);
    
    return 0;
}