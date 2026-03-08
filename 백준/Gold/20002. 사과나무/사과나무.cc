#include <iostream>

using namespace std;

int map[301][301];

int main() {
    int n;
    
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> map[i][j];
            
            map[i][j] += map[i-1][j] + map[i][j-1] - map[i-1][j-1];
        }
    }
    
    int result = -1000;
    
    for(int k=1; k<=n; k++) {
        for(int i=k; i<=n; i++) {
            for(int j=k; j<=n; j++) {
                int temp = map[i][j] - map[i-k][j] - map[i][j-k] + map[i-k][j-k];
                
                result = max(result, temp);
            }
        }
    }
    
    cout << result;
    
    return 0;
}