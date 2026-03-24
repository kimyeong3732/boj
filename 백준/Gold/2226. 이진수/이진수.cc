#include <iostream>

using namespace std;

string oper(string a, int order) {
    string result = "";
    
    if(order == -1) {
        bool state = true;
        
        for(int i=a.size()-1; i>=0; i--) {
            if(state) {
                char temp = a[i];
                
                if(temp == '0') {
                    temp = '9';
                }
                
                else {
                    temp--;
                    state = false;
                    
                    if(i==0 && temp=='0')
                        continue;
                }
                
                result = temp + result;
            }
            
            else {
                result = a[i] + result;
            }
        }
    }
    
    else if(order == 1) {
        bool state = true;
        
        for(int i=a.size()-1; i>=0; i--) {
            if(state) {
                char temp = a[i];
                
                if(temp == '9') {
                    temp = '0';
                    
                    if(i == 0) {
                        result = temp + result;
                        temp = '1';
                    }
                }
                
                else {
                    temp++;
                    state = false;
                }
                
                result = temp + result;
            }
            
            else {
                result = a[i] + result;
            }
        }
    }
    
    else {
        int c = 0;
        
        for(int i=a.size()-1; i>=0; i--) {
            int temp = (a[i] - '0') * 2 + c;
            
            c = temp / 10;
            char input = temp % 10 + '0';
            
            result = input + result;
        }
        
        if(c != 0) {
            char input = c + '0';
            
            result = input + result;
        }
    }
    
    return result;
}

int main() {
    int n;
    string dp[1000];
    
    cin >> n;
    
    dp[0] = "0";
    
    for(int i=1; i<n; i++) {
        dp[i] = oper(dp[i-1], 0);
        
        if(i%2 == 1)
            dp[i] = oper(dp[i], 1);
        
        else
            dp[i] = oper(dp[i], -1);
    }
    
    cout << dp[n-1];
    
    return 0;
}