#include <iostream>
#include <regex>

using namespace std;

int main() {
    string s;
    regex re("(100+1+|01)+");
    
    cin >> s;
    
    if(regex_match(s, re))
        cout << "SUBMARINE";
    
    else
        cout << "NOISE";
    
    return 0;
}