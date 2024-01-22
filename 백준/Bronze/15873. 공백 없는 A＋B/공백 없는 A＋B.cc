#include <iostream>
using namespace std;

int main() {
    int num;
    int result;
    
    cin >> num;
    
    if((num%10) == 0) {
        result = num % 100;
        result += num / 100;
    }
    else {
        result = num % 10;
        result += num / 10;
    }
    
    cout << result << '\n';
    
    return 0;
}