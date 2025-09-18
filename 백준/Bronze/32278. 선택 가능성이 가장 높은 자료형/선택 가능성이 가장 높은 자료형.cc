#include <iostream>

using namespace std;

int main() {
    long long n;
    
    cin >> n;
    
    if(n>=-32768 && n<32768)
        cout << "short";
    else if(n>=-2147483648 && n<2147483648)
        cout << "int";
    else
        cout << "long long";
    
    return 0;
}