#include <iostream>

using namespace std;

int main() {
    int num = 0;
    string result = "";
    string s;
    
    cin >> s;
    
    int i;
    int state = 0;
    for(i=0; i<s.size()%3; i++) {
        num *= 2;
        num += s[i] - '0';
    }
    
    if(i > 0) {
        result += num + '0';
        num = 0;
    }
    
    for(i; i<s.size(); i++) {
        num *= 2;
        num += s[i] - '0';
        state++;
        
        if(state == 3) {
            result += num + '0';
            num = 0;
            state = 0;
        }
    }
    
    cout << result;
    
    return 0;
}