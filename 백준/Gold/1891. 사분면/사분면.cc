#include <iostream>

using namespace std;

int main() {
    int n;
    string input;
    
    cin >> n >> input;
    
    long long x=0, y=0;
    long long digit = 1;
    
    for(int i=n-1; i>=0; i--) {
        if(input[i] != '3') {
            if(input[i]=='1' || input[i]=='4')
                x += digit;
            
            if(input[i]=='1' || input[i]=='2')
                y += digit;
        }
        
        digit *= 2;
    }
    
    long long xi, yi;
    
    cin >> xi >> yi;
    
    x += xi;
    y += yi;
    
    if(x<0 || x>=digit || y<0 || y>=digit) {
        cout << -1;
    }
    
    else {
        digit /= 2;
        
        while(digit > 0) {
            if(x >= digit) {
                if(y >= digit) {
                    cout << 1;
                    
                    y -= digit;
                }
                
                else {
                    cout << 4;
                }
                
                x -= digit;
            }
            
            else {
                if(y >= digit) {
                    cout << 2;
                    
                    y -= digit;
                }
                
                else {
                    cout << 3;
                }
            }
            
            digit /= 2;
        }
    }
    
    return 0;
}