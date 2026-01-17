#include <iostream>

using namespace std;

int main() {
    long long s, e;
    
    cin >> s >> e;
    
    long long d = e - s;
    
    long long c = 0;
    
    while(c*c <= d)
        c++;
    
    c--;
    
    long long result = c;
    
    if(c != 0) {
        result *= 2;
        result--;
    }
    
    d -= c * c;
    
    if(d != 0) {
        d--;
        
        result += d / c + 1;
    }
    
    cout << result;
    
    return 0;
}