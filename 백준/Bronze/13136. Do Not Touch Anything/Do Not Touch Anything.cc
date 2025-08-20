#include <iostream>

using namespace std;

int main() {
    long long m, n, c;
    
    cin >> m >> n >> c;
    
    long long mm = m / c;
    long long nn = n / c;
    
    if(m%c > 0)
        mm++;
    
    if(n%c > 0)
        nn++;
    
    cout << mm * nn;
    
    return 0;
}