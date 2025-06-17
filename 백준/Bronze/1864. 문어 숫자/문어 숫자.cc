#include <iostream>

using namespace std;

int main() {
    string s;
    
    cin >> s;
    
    while(s.compare("#") != 0) {
        int num = 0;
        
        for(int i=0; i<s.size(); i++) {
            num *= 8;
            
            switch(s[i]) {
                case '-':
                    break;
                case '\\':
                    num += 1;
                    break;
                case '(':
                    num += 2;
                    break;
                case '@':
                    num += 3;
                    break;
                case '?':
                    num += 4;
                    break;
                case '>':
                    num += 5;
                    break;
                case '&':
                    num += 6;
                    break;
                case '%':
                    num += 7;
                    break;
                case '/':
                    num += -1;
                    break;
                default:
                    break;
            }
        }
        
        cout << num << "\n";
        
        cin >> s;
    }
    
    return 0;
}