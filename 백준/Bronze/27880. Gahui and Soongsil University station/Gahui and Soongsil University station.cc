#include <iostream>

using namespace std;

int main() {
    int result = 0;
    
    for(int i=0; i<4; i++) {
        string s;
        int n;
        
        cin >> s >> n;
        
        if(s == "Es")
            result += 21 * n;
        else
            result += 17 * n;
    }
    
    cout << result;
    
    return 0;
}