#include <iostream>

using namespace std;

int main() {
    for(int i=0; i<3; i++) {
        int max = 1;
        int now = 1;
        char c = '0';
        string s;
        
        cin >> s;
        
        for(int j=0; j<8; j++) {
            if(c == s[j]) {
                now++;
                
                if(max < now)
                    max = now;
            }
            
            else {
                c = s[j];
                now = 1;
            }
        }
        
        cout << max << "\n";
    }
    
    return 0;
}