#include <iostream>

using namespace std;

int alpha[26];

int main() {
    string s;
    
    cin >> s;
    
    for(int i=0; i<s.size(); i++)
        alpha[s[i]-'a']++;
    
    cin >> s;
    
    for(int i=0; i<s.size(); i++)
        alpha[s[i]-'a']--;
    
    int result = 0;
    
    for(int i=0; i<26; i++) {
        if(alpha[i] < 0)
            result -= alpha[i];
        else
            result += alpha[i];
    }
    
    cout << result;
    
    return 0;
}