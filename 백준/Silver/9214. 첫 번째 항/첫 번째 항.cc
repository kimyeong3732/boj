#include <iostream>

using namespace std;

int main() {
    string s;
    int t = 1;
    
    cin >> s;
    
    while(s.size()>1 || s[0]!='0') {
        string c = s;
        string r = "";
        
        while(true) {
            if(c.size()%2 == 1) {
                cout << "Test " << t << ": " << c << "\n";
                break;
            }
            
            for(int i=0; i<c.size(); i+=2)
                for(int j=0; j<c[i]-'0'; j++)
                    r += c[i+1];
            
            if(r.size()%2==1 || c==r) {
                cout << "Test " << t << ": " << r << "\n";
                break;
            }
            
            c = r;
            r = "";
        }
        
        cin >> s;
        t++;
    }
    
    return 0;
}