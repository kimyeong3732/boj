#include <iostream>

using namespace std;

int main() {
    int g1, g2, s1, s2, b1, b2;
    
    cin >> g1 >> s1 >> b1;
    cin >> g2 >> s2 >> b2;
    
    int g = g1 - g2;
    int s = s1 - s2;
    int b = b1 - b2;
    
    int result = 0;
    
    if(g < 0) {
        s += g * 11;
        
        result -= g;
        
        g = 0;
    }
    
    if(b < 0) {
        int temp = (-1 * b) / 9;
        
        if((-1*b)%9 > 0)
            temp ++;
        
        b += temp * 9;
        
        result += temp;
        
        s -= temp;
    }
    
    if(s < 0) {
        if((-1*s) > g*9+b/11) {
            result = -1;
        }
        
        else {
            if(-9*g <= s) {
                int temp = (-1 * s) / 9;
                
                if((-1*s)%9 > 0)
                    temp++;
                
                result += temp;
            }
            
            else {
                s += g * 9;
                
                result += g;
                
                result -= s;
            }
        }
    }
    
    cout << result;
    
    return 0;
}