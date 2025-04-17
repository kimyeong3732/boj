#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string s;
    
    getline(cin, s);
    
    while(s.size()>1 || s[0]!='#') {
        int num = 0;
        
        for(int i=0; i<s.size(); i++)
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                num++;
        
        cout << num << '\n';
        
        getline(cin, s);
    }
    
    return 0;
}