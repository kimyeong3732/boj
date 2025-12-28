#include <iostream>

using namespace std;

int main() {
    int t;
    int check[4][3] = {{1, 2, 3}, {2, 0, 3}, {0, 1, 3}, {0, 2, 1}};
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int a[4], b[4];
        
        for(int j=0; j<4; j++)
            cin >> a[j];
        
        for(int j=0; j<4; j++)
            cin >> b[j];
        
        bool state;
        
        for(int j=0; j<4; j++) {
            state = true;
            
            if(a[0] != b[j]) {
                state = false;
            }
            
            else {
                for(int k=0; k<3; k++) {
                    state = true;
                    
                    for(int l=0; l<3; l++) {
                        if(a[1+l] != b[check[j][(l+k)%3]]) {
                            state = false;
                            break;
                        }
                    }
                    
                    if(state)
                        break;
                }
            }
            
            if(state)
                break;
        }
        
        if(state)
            cout << "1\n";
        
        else
            cout << "0\n";
    }
    
    return 0;
}