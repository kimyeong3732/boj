#include <iostream>

using namespace std;

int main() {
    string t = "eh?";
    string s;
    bool state = true;
    
    getline(cin, s);
    
    for(int i=s.size()-3; i<s.size(); i++) {
        if(s[i] != t[i-s.size()+3]) {
            state = false;
            break;
        }
    }
    
    if(state)
        cout << "Canadian!";
    else
        cout << "Imposter!";
    
    return 0;
}