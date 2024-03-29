#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
char map[1000][1000];
bool visit[1000][1000];
int parent[1000000];
bool parent_bool [1000000];

int get_parent(int num ){
    if(parent[num] == num)
        return num;
        
    return parent[num] = get_parent(parent[num]);
}

void make_group(int x, int y) {
    queue<int> q;
    
    q.push(y*M+x);
    visit[y][x] = true;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        int cp = get_parent(node);
        int nx = node % M;
        int ny = node / M;
        
        switch(map[ny][nx]) {
        case 'U':
            ny--;
            break;
        case 'D':
            ny++;
            break;
        case 'L':
            nx--;
            break;
        case 'R':
            nx++;
            break;
        }
        
        int np = get_parent(ny*M+nx);
        
        if(cp != np) {
            parent[node] = np;
        }
        
        if(!visit[ny][nx]) {
            q.push(ny*M+nx);
            visit[ny][nx] = true;
        }
    }
}

int check() {
    int count = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(visit[i][j])
                continue;
                
            make_group(j, i);
            
            if(!parent_bool[get_parent(i*M+j)]) {
                parent_bool[get_parent(i*M+j)] = true;
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    cin >> N >> M;
    
    for(int i=0; i<N; i++ ){
        string str;
        cin >> str;
        
        for(int j=0; j<M; j++) {
            map[i][j] = str[j];
            parent[i * M + j] = i * M + j;
        }
    }
    
    cout << check();
    
    return 0;
}