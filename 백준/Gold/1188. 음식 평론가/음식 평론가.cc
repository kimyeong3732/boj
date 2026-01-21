#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

int main() {
    int a, b;
    
    cin >> a >> b;
    
    int l = a * b / gcd(a, b);
    
    int ar = l / a;
    int br = l / b;
    int result = 0;
    
    for(int i=br; i<l; i+=br)
        if(i%ar != 0)
            result++;
    
    cout << result;
    
    return 0;
}