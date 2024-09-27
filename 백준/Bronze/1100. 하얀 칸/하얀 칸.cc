#include <iostream>

using namespace std;

int main() {
    int result = 0;
    string board[8];
    
    for(int i=0; i<8; i++) {
        cin >> board[i];
    }
    
    for(int i=0; i<8; i++) {
        for(int j=i%2; j<8; j+=2) {
            if(board[i][j] == 'F') {
                result++;
            }
        }
    }
    
    cout << result;
    
    return 0;
}