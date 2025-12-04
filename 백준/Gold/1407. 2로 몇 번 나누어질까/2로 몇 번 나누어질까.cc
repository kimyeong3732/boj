#include <iostream>

using namespace std;

long long find(long long num, long long digit) {
    if(num == 0)
        return 0;
    
    return (num + 1) / 2 * digit + find(num/2, digit*2);
}

int main() {
    long long a, b;
    
    cin >> a >> b;
    
    cout << find(b, 1) - find(a-1, 1);
    
    return 0;
}