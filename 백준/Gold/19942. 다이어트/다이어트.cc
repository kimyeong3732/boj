#include <iostream>

using namespace std;

int n;
int d[4];
int now[5];
int input[16][5];
int rn = 7501;
bool visit[16];
bool check[16];

void find(int s) {
    bool state = true;
    
    for(int i=0; i<4; i++) {
        if(d[i] > now[i]) {
            state = false;
            break;
        }
    }
    
    if(state) {
        if(now[4] < rn) {
            for(int i=1; i<=n; i++)
                check[i] = visit[i];
            
            rn = now[4];
        }
        
        return;
    }
    
    if(s > n)
        return;
    
    visit[s] = true;
    
    for(int i=0; i<5; i++)
        now[i] += input[s][i];
    
    find(s+1);
    
    visit[s] = false;
    
    for(int i=0; i<5; i++)
        now[i] -= input[s][i];
    
    find(s+1);
}

int main() {
    cin >> n;
    
    for(int i=0; i<4; i++)
        cin >> d[i];
    
    for(int i=1; i<=n; i++)
        for(int j=0; j<5; j++)
            cin >> input[i][j];
    
    find(1);
    
    if(rn == 7501) {
        cout << "-1\n";
    }
    
    else {
        cout << rn << "\n";
        
        for(int i=1; i<=n; i++)
            if(check[i])
                cout << i << " ";
    }
    
    return 0;
}