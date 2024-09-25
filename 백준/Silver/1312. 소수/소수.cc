#include <iostream>

using namespace std;

int main() {
    long long a, b, n;
    long long result = 0;
    
    cin >> a >> b >> n;
    
    for(int i=0; i<n; i++) {
        a *= 10;
        result = (a / b) % 10;
        a %= b;
    }
    
    cout << result;
    
    return 0;
}