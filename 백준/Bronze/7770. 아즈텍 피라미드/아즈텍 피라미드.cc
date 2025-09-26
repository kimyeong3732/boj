#include <iostream>

using namespace std;

int main() {
    long long num = 0;
    long long result = 1;
    long long c = 1;
    long long sum = 1;
    
    cin >> num;
    
    while(sum <= num) {
        c += result * 4;
        result++;
        
        sum += c;
    }
    
    cout << result - 1;
    
    return 0;
}