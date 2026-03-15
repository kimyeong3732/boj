#include <iostream>
#include <regex>

using namespace std;

int main() {
    int n;
    regex r("(100+1+|01)+");
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string s;
        
        cin >> s;
        
        if(regex_match(s, r))
            cout << "YES\n";
        
        else
            cout << "NO\n";
    }
    
    return 0;
}