#include <iostream>

using namespace std;

int i;

int find(string s) {
    int result = 0;
    
    for(i; i<s.size(); i++) {
        if(i<s.size()-1 && s[i+1]=='(') {
            int mul = s[i] - '0';
            
            i += 2;
            
            result += mul * find(s);
        }
        
        else if(s[i] == ')') {
            return result;
        }
        
        else {
            result++;
        }
    }
    
    return result;
}

int main() {
    string s;
    
    cin >> s;
    
    cout << find(s);
    
    return 0;
}