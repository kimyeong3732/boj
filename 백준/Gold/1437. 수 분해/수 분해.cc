#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    if(n < 5) {
        cout << n;
    }
    
    else {
        int l = n / 3;
        int r = n % 3;
        int result = 1;
        
        if(r != 0) {
            if(r == 1) {
                result *= 2;
                l--;
            }
            
            result *= 2;
        }
        
        for(int i=0; i<l; i++) {
            result *= 3;
            result %= 10007;
        }
        
        cout << result;
    }
    
    return 0;
}