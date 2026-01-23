#include <iostream>

using namespace std;

int n;
bool state;

void find(string s, int c) {
    if(state)
        return;
    
    for(int i=1; i<=s.size()/2; i++)
        if(s.substr(s.size()-i, i) == s.substr(s.size()-i*2, i))
            return;
    
    if(c == n) {
        cout << s;
        state = true;
        return;
    }
    
    find(s+"1", c+1);
    find(s+"2", c+1);
    find(s+"3", c+1);
}

int main() {
    string s = "";
    
    cin >> n;
    
    find(s, 0);
    
    return 0;
}