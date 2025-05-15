#include <iostream>

using namespace std;

int main() {
    long long result = 0;
    long long num;
    
    cin >> num;
    
    for(long long i=1; i<num; i++)
        result += i;
    
    result *= num + 1;
    
    cout << result;
    
    return 0;
}