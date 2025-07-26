#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main() {
    int a1, a2, b1, b2;
    int ar, br;
    
    cin >> a1 >> b1 >> a2 >> b2;
    
    br = b1 * b2;
    ar = a1 * b2 + a2 * b1;
    
    int g = gcd(ar, br);
    
    cout << ar/g << " " << br/g;
    
    return 0;
}