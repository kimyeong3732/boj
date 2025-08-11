#include <iostream>

using namespace std;

int main() {
    int num = 0;
    bool state = false;
    string s;
    string result = "";
    
    cin >> s;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'X') {
            num++;
        }
        else {
            for(int j=0; j<num/4; j++)
                result += "AAAA";
            
            num %= 4;
            
            for(int j=0; j<num/2; j++)
                result += "BB";
            
            num %= 2;
            
            result += ".";
            
            if(num != 0) {
                state = true;
                break;
            }
        }
    }
    
    for(int j=0; j<num/4; j++)
        result += "AAAA";
    
    num %= 4;
    
    for(int j=0; j<num/2; j++)
        result += "BB";
    
    num %= 2;
    
    if(num != 0) {
        state = true;
    }
    
    if(state)
        cout << -1;
    else
        cout << result;
    
    return 0;
}