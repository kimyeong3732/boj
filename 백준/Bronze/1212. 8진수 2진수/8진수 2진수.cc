#include <iostream>

using namespace std;

int main() {
    string s;
    bool state = true;
    
    cin >> s;
    
    for(int i=0; i<s.length(); i++) {
        int num = s[i] - '0';
        
        int result[3];
        
        for(int j=2; j>=0; j--) {
            result[j] = num % 2;
            num /= 2;
        }
        
        for(int j=0; j<3; j++) {
            if(state & result[j] == 0) {
                continue;
            }
            cout << result[j];
            state = false;
        }
    }
    
    if(state) {
        cout << 0;
    }
    
    return 0;
}