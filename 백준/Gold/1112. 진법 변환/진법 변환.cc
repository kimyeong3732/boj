#include <iostream>

using namespace std;

int main() {
    int num, d;
    
    cin >> num >> d;
    
    if(num == 0) {
        cout << num;
    }
    
    else {
        string result = "";
        
        bool dm = d < 0;
        bool nm = num < 0;
        
        if(dm) {
            while(num != 0) {
                int digit = num % d;
                num /= d;
                
                if(digit < 0) {
                    num++;
                    digit -= d;
                }
                
                result += (char)(digit + '0');
            }
            
            for(int i=result.size()-1; i>=0; i--)
                cout << result[i];
        }
        else {
            if(nm)
                num *= -1;
            
            while(num > 0) {
                int digit = num % d;
                num /= d;
                
                result += (char)(digit + '0');
            }
            
            if(nm)
                cout << "-";
            
            for(int i=result.size()-1; i>=0; i--)
                cout << result[i];
        }
    }
    
    return 0;
 }