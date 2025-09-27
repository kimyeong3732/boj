#include <iostream>

using namespace std;

int main() {
    string s;
    
    cin >> s;
    
    int num[2] = {0, 0};
    int c = 0;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='0' && s[i]<='9') {
            num[c] *= 10;
            num[c] += s[i] - '0';
            
            if(num[c] == 0) {
                c = 2;
                break;
            }
        }
        
        else if(s[i] == '+') {
            if(num[0] == 0) {
                c = 2;
                break;
            }
            
            c++;
            
            if(c > 1)
                break;
        }
        
        else {
            c = 2;
            break;
        }
    }
    
    if(c==1 && num[0]==num[1])
        cout << "CUTE";
    
    else
        cout << "No Money";
    
    return 0;
}