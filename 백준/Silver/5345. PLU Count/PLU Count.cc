#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    string check = "pPlLuU";
    
    cin >> n;
    getline(cin, s);
    
    for(int i=0; i<n; i++) {
        int result = 0;
        int c = 0;
        
        getline(cin, s);
        
        for(int j=0; j<s.size(); j++) {
            if(s[j]==check[c*2] || s[j]==check[c*2+1]) {
                c++;
                
                if(c == 3) {
                    c = 0;
                    result++;
                }
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}