#include <iostream>

using namespace std;

int main() {
    long long n, k;
    
    cin >> n >> k;
    
    long long r = 0;
    long long digit = 1;
    
    while(n+k > 0) {
        if(k>0 && (n==0 || n%2==0)) {
            r += digit * (k % 2);
            k /= 2;
        }
        
        n /= 2;
        digit *= 2;
    }
    
    cout << r;
    
    return 0;
}