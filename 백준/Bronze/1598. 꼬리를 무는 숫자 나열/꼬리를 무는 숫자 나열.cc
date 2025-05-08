#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    cin >> a >> b;
    
    int ax=(a-1)/4, ay=(a-1)%4;
    int bx=(b-1)/4, by=(b-1)%4;
    
    int rx=ax-bx, ry=ay-by;
    if(rx < 0)
        rx *= -1;
    if(ry < 0)
        ry *= -1;
    
    cout << rx+ry;
    
    return 0;
}