#include <iostream>

using namespace std;;

int map[1000][1000];

int main() {
    int n, m;
    
    cin >> n >> m;
    
    while(n+m > 0) {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> map[i][j];
        
        int result = 0;
        
        for(int i=0; i<n; i++)
            result = max(result, map[i][0]);
        
        for(int j=0; j<m; j++)
            result = max(result, map[0][j]);
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(map[i][j] == 1) {
                    map[i][j] = min(map[i-1][j], min(map[i][j-1], map[i-1][j-1])) + 1;
                    
                    if(result < map[i][j])
                        result = map[i][j];
                }
            }
        }
        
        cout << result << "\n";
        
        cin >> n >> m;
    }
    
    return 0;
}