#include <iostream>

using namespace std;

int main() {
    int a, b, x, y, t;
    
    cin >> a >> x >> b >> y >> t;
    
    if(t >= 30)
        a += (t - 30) * x * 21;
    
    if(t >= 45)
        b += (t - 45) * y * 21;
    
    cout << a << " " << b;
    
    return 0;
}