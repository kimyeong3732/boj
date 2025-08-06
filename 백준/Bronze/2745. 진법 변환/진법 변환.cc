#include <iostream>

using namespace std;

int main() {
    string s;
    int b;
    
    int result = 0;
    
    cin >> s >> b;
    
    for(int i=0; i<s.size(); i++) {
        result *= b;
        
        if(s[i]>='A' && s[i]<='Z')
            result += s[i] - 'A' + 10;
        else
            result += s[i] -'0';
    }
    
    cout << result;
    
    return 0;
}