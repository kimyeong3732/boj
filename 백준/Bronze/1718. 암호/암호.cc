#include <iostream>

using namespace std;

int main() {
    string s, c;
    
    getline(cin, s);
    getline(cin, c);
    
    for(int i=0; i<s.size(); i++) {
        if(s[i] != ' ') {
            int temp1 = s[i] - 'a';
            int temp2 = c[i%c.size()] - 'a' + 1;
            
            temp1 = (temp1 + (26 - temp2)) % 26;
            
            s[i] = temp1 + 'a';
        }
    }
    
    cout << s;
    
    return 0;
}