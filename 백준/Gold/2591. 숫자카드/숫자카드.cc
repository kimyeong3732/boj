#include <iostream>

using namespace std;

int dp[41];

bool check(char a, char b) {
    if(a == '0')
        return false;
    
    int num = (a-'0') * 10 + (b-'0');
    
    return num < 35;
}

int main() {
    string s;
    
    cin >> s;
    
    dp[0] = 1;
    
    for(int i=0; i<s.size(); i++) {
        if(i>0 && check(s[i-1], s[i]))
            dp[i+1] += dp[i-1];
        
        if(s[i] != '0')
            dp[i+1] += dp[i];
    }
    
    cout << dp[s.size()];
    
    return 0;
}