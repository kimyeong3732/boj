#include <iostream>

using namespace std;

int main() {
    string s[4];
    
    for(int i=0; i<4; i++)
        cin >> s[i];
    
    int result = 0;
    
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(s[i][j] != '.') {
                int num = s[i][j] - 'A';
                int nx = num % 4;
                int ny = num / 4;
                
                nx -= j;
                ny -= i;
                
                if(nx < 0)
                    nx *= -1;
                if(ny < 0)
                    ny *= -1;
                
                result += nx + ny;
            }
        }
    }
    
    cout << result;
    
    return 0;
}