#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    
    cin >> a >> b >> c;
    
    int temp = min(a, b);
    temp = min(temp, c);
    
    if(temp<3 || (a==b && b==c && a==3))
        cout << 0;
    
    else
        cout << (temp-1) / 2;
    
    return 0;
}