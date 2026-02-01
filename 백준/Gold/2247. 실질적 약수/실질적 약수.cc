#include <iostream>

using namespace std;

int main() {
    long long n;
    long long result = 0;
    
    cin >> n;
    
    for(long long i=2; i<n; i++) {
        if(n/i-1 <= 0)
            break;
        
        result += i * (n/i - 1) % 1000000;
        result %= 1000000;
    }
    
    cout << result;
    
    return 0;
}