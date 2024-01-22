#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;
};

void BFS(vector<string> map, vector<vector<bool>> visit) {
	int n = map.size(), m = map[0].size();
    int sx = -1, sy;
    queue<point> q;
    int count = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 'I') {
                sx = j;
                sy = i;
                break;
            }
        }
        
        if(sx >= 0)
            break;
    }
    
    q.push({sx, sy});
    visit[sy][sx] = true;
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    while(!q.empty()) {
    	int x = q.front().x;
    	int y = q.front().y;
    	q.pop();
    	
    	if(map[y][x] == 'P') {
    		count++;
    	}
    	
    	for(int i=0; i<4; i++) {
    		int nx = x + dx[i];
    		int ny = y + dy[i];
    		
    		if(nx>=0 && nx<m && ny>=0 && ny<n && map[ny][nx]!='X' && !visit[ny][nx]) {
    			visit[ny][nx] = true;
    			q.push({nx, ny});
    		}
    	}
    }
    
    if(count > 0)
    	cout << count;
    else
    	cout << "TT";
}

int main() {
    int n, m;
    vector<string> map;
    vector<vector<bool>> visit;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        vector<bool> visity;
        string str = "";
        
        cin >> str;
        
        map.push_back(str);
        
        for(int j=0; j<m; j++) {
        	
        	visity.push_back(false);
        }
        
        visit.push_back(visity);
    }
    
    BFS(map, visit);
    
    return 0;
}