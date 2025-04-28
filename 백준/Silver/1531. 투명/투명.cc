#include <iostream>

using namespace std;

int map[100][100];

int main() {
    int n, m;
    int result = 0;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        int x1, x2, y1, y2;
        
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int j=x1-1; j<x2; j++) {
            for(int k=y1-1; k<y2; k++) {
                map[k][j]++;
            }
        }
    }
    
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(map[j][i] > m) {
                result++;
            }
        }
    }
    
    cout << result;
    
    return 0;
}