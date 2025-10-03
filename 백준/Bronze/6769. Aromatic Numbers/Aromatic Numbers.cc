#include <iostream>

using namespace std;

int main() {
    int result = 0;
    int alpha[26] = {0, 0, 100, 500, 0,
                     0, 0, 0, 1, 0,
                     0, 50, 1000, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 5, 0, 10, 0, 0};
    string s;
    
    cin >> s;
    
    s += "0I";
    
    for(int i=0; i<s.size(); i+=2) {
        int d = s[i] - '0';
        int a = s[i+1] - 'A';
        int b = s[i+3] - 'A';
        
        if(alpha[b] > alpha[a])
            result -= d * alpha[a];
        
        else
            result += d * alpha[a];
    }
    
    cout << result;
    
    return 0;
}