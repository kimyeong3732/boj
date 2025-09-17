#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    cin >> a >> b;
    
    int h = b / 2;
    
    if(b%2 > 0)
        h++;
    
    if(a >= h)
        cout << "E";
    else
        cout << "H";
    
    return 0;
}