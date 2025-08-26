#include <iostream>

using namespace std;

int main() {
    double a, b, c;
    
    cin >> a >> b >> c;
    
    double result = a * b / c;
    
    if(result < a/b*c)
        result = a/b*c;
    
    cout << (int) result;
    
    return 0;
}