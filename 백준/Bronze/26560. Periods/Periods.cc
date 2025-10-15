#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n;
    getline(cin, s);
    
    for(int i=0; i<n; i++) {
        getline(cin, s);
        
        if(s[s.size()-1] != '.')
            s += ".";
        
        cout << s << "\n";
    }
    
    return 0;
}