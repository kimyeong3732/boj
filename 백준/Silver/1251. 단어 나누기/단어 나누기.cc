#include <iostream>

using namespace std;

string make(int a, int b, string s) {
    string r = "";
    
    for(int i=a; i>=0; i--)
        r += s[i];
    
    for(int i=b; i>a; i--)
        r += s[i];
    
    for(int i=s.size()-1; i>b; i--)
        r += s[i];
    
    return r;
}

int main() {
    string s;
    
    cin >> s;
    
    string r = "z";
    r += s;
    
    for(int i=0; i<s.size()-2; i++) {
        for(int j=i+1; j<s.size()-1; j++) {
            string temp = make(i, j, s);
            
            if(r.compare(temp) > 0)
                r = temp;
        }
    }
    
    cout << r;
    
    return 0;
}