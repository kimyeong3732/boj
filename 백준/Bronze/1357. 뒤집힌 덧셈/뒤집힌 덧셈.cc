#include <iostream>

using namespace std;

int rev(int a) {
    int num = a;
    int result = 0;
    
    while(num > 0) {
        result *= 10;
        result += num % 10;
        
        num /= 10;
    }
    
    return result;
}

int main() {
    int a, b;
    
    cin >> a >> b;
    
    cout << rev(rev(a)+rev(b));
    
    return 0;
}