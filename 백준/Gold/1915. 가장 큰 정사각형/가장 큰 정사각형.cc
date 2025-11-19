#include <iostream>

using namespace std;

int n, m;
int map[1000][1000];

int main() {
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        string s;
        
        cin >> s;
        
        for(int j=0; j<m; j++)
            if(s[j] == '1')
                map[i][j] = 1;
    }
    
    int result = 0;
    
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(map[i][j] == 1) {
                int mn = min(map[i-1][j], map[i-1][j-1]);
                mn = min(mn, map[i][j-1]);
                
                map[i][j] = mn + 1;
            }
        }
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            result = max(map[i][j], result);
    
    cout << result * result;
    
    return 0;
}