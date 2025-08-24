#include <iostream>

using namespace std;

int alpha[26];

int main() {
    string s;
    
    cin >> s;
    
    for(int i=0; i<s.size(); i++)
        alpha[s[i]-'A']++;
    
    string front="", back="";
    
    char c = '0';
    
    for(int i=0; i<26; i++) {
        if(alpha[i]%2 != 0) {
            if(c != '0') {
                front = "I'm Sorry Hanso";
                back = "";
                c = 'o';
                break;
            }
            
            c = i + 'A';
        }
        
        char temp = i + 'A';
        
        for(int j=0; j<alpha[i]/2; j++) {
            front += temp;
            back = temp + back;
        }
    }
    
    cout << front;
    
    if(c != '0')
        cout << c;
    
    cout << back;
    
    return 0;
}