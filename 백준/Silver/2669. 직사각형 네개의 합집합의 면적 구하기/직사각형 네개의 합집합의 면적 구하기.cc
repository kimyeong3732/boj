#include <iostream>

using namespace std;

int map[100][100];

int main() {
    int result = 0;
    
    for(int i=0; i<4; i++) {
        int x1, x2, y1, y2;
        
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int j=x1; j<x2; j++) {
            for(int k=y1; k<y2; k++) {
                if(map[j][k] == 0) {
                    map[j][k] = 1;
                }
            }
        }
    }
    
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            result += map[i][j];
        }
    }
    
    cout << result;
    
    return 0;
}