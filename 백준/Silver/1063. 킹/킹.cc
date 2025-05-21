#include <iostream>

using namespace std;

int main() {
    string input;
    int t;
    int x[2];
    int y[2];
    
    for(int i=0; i<2; i++) {
        cin >> input;
        
        x[i] = input[0] - 'A';
        y[i] = input[1] - '1';
    }
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        string cmd;
        
        cin >> cmd;
        
        int tx = x[0];
        int ty = y[0];
        
        for(int j=0; j<cmd.size(); j++) {
            switch(cmd[j]) {
                case 'R':
                    tx += 1;
                    break;
                case 'L':
                    tx -= 1;
                    break;
                case 'B':
                    ty -= 1;
                    break;
                case 'T':
                    ty += 1;
                    break;
                default:
                    break;
            }
        }
            
        if(tx>=0 && tx<8 && ty>=0 && ty<8) {
            if(tx==x[1] && ty==y[1]) {
                int ttx = x[1];
                int tty = y[1];
                
                for(int j=0; j<cmd.size(); j++) {
                    switch(cmd[j]) {
                        case 'R':
                            ttx += 1;
                            break;
                        case 'L':
                            ttx -= 1;
                            break;
                        case 'B':
                            tty -= 1;
                            break;
                        case 'T':
                            tty += 1;
                            break;
                        default:
                            break;
                    }
                }
                if(ttx>=0 && ttx<8 && tty>=0 && tty<8) {
                    x[1] = ttx;
                    y[1] = tty;
                }
                else {
                    continue;
                }
            }
            x[0] = tx;
            y[0] = ty;
        }
    }
    
    for(int i=0; i<2; i++) {
        cout << (char)(x[i]+'A') << y[i]+1 << "\n";
    }
    
    return 0;
}