#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    n--;
    
    if((n/4)%2==0)
        cout << (n % 4) + 1;
    else
        cout << 5 - (n % 4);
    
    return 0;
}