#include <iostream>

using namespace std;

int main() {
    long long n;
    long long num = 1;
    long long result = 0;
    
    cin >> n;
    
    while(n >= num) {
        n -= num;
        result++;
        num++;
    }
    
    cout << result;
    
    return 0;
}