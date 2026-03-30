#include <iostream>

using namespace std;

int parents[201];

int getParent(int num) {
    if(parents[num] == num)
        return num;
    
    return parents[num] = getParent(parents[num]);
}

void unionParent(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);
    
    if(pa <= pb)
        parents[pb] = pa;
    
    else
        parents[pa] = pb;
}

int main() {
    int n, m;
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++)
        parents[i] = i;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int check;
            
            cin >> check;
            
            if(check == 1)
                unionParent(i, j);
        }
    }
    
    int cp = 0;
    bool state = false;
    
    for(int i=0; i<m; i++) {
        int num;
        
        cin >> num;
        
        if(i == 0) {
            cp = getParent(num);
        }
        
        else {
            int tp = getParent(num);
            
            if(cp != tp) {
                state = true;
                break;
            }
        }
    }
    
    if(state)
        cout << "NO";
    
    else
        cout << "YES";
    
    return 0;
}