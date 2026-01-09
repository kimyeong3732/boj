#include <iostream>

using namespace std;

int main() {
    int l, r, k;
    
    cin >> l >> r >> k;
    
    int result = 0;
    
    switch(k) {
    case 2:
        if(r >= 3) {
            if(l >= 3)
                result = r - l + 1;
            
            else
                result = r - 2;
        }
        
        break;
    case 3:
        if(r >= 6) {
            if(l >= 6) {
                result = (r / 3) - (l / 3);
                
                if(l%3 == 0)
                    result++;
            }
            
            else {
                result = (r / 3) - 1;
            }
        }
        
        break;
    case 4:
        if(r >= 10) {
            if(l >= 10) {
                result = (r / 6) - (l / 6);
                
                if(r%6 >= 4)
                    result++;
                
                if(l%6 > 4)
                    result--;
            }
            
            else {
                result = (r / 6) - 1;
                
                if(r%6 >= 4)
                    result++;
            }
            
            if(r >= 14) {
                if(l >= 14) {
                    result += (r / 6) - (l / 6);
                    
                    if(r%6 >= 2)
                        result++;
                    
                    if(l%6 > 2)
                        result--;
                }
                
                else {
                    result += (r / 6) - 2;
                    
                    if(r%6 >= 2)
                        result++;
                }
            }
            
            if(r >= 18) {
                if(l >= 18) {
                    result += (r / 6) - (l / 6);
                    
                    if(l%6 == 0)
                        result++;
                }
                
                else {
                    result += (r / 6) - 2;
                }
            }
        }
        
        break;
    case 5:
        if(r >= 15) {
            if(l >= 15) {
                result = (r / 5) - (l / 5);
                
                if(l%5 == 0)
                    result++;
            }
            
            else {
                result = (r / 5) - 2;
            }
        }
        break;
    default:
        break;
    }
    
    cout << result;

    return 0;
}