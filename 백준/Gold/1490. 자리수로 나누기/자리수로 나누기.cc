#include <iostream>

using namespace std;

bool check(long long a, long long n) {
    long long temp = n;
    
    while(temp > 0) {
        long long c = temp % 10;
        
        if(c!=0 && a%c != 0)
            return false;
        
        temp /= 10;
    }
    
    return true;
}

int main() {
    long long n;
    
    cin >> n;
    
    if(check(n, n)) {
        cout << n;
    }
    else {
        long long digit = 10;
        bool state = false;
        
        while(true) {
            long long r = n * digit;
            
            for(long long i=0; i<digit; i++) {
                if(check(r+i, n)) {
                    cout << r + i;
                    state = true;
                    break;
                }
            }
            
            if(state)
                break;
            
            digit *= 10;
        }
    }
    
    return 0;
}