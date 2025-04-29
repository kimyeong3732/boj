#include <iostream>

using namespace std;

int main() {
    int n, m;
    int map[300][300];
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int temp;
            
            cin >> temp;
            
            map[i][j] = temp;
        }
    }
    
    int tc;
    
    cin >> tc;
    
    for(int t=0; t<tc; t++) {
        int x1, x2, y1, y2;
        int sum = 0;
        
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i=x1-1; i<x2; i++) {
            for(int j=y1-1; j<y2; j++) {
                sum += map[i][j];
            }
        }
        
        cout << sum << "\n";
    }
    
    return 0;
}