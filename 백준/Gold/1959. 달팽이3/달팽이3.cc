#include <iostream>

using namespace std;

int main() {
    long long m, n;
    
    cin >> m >> n;
    
    if(m > n)
        cout << (n-1)*2+1;
    
    else
        cout << (m-1)*2;
    
    cout << "\n";
    
    if(m == n) {
        if(m%2 == 1)
            cout << m/2+1 << " " << m/2+1;
        
        else
            cout << m/2+1 << " " << m/2;
    }
    
    else if(m > n) {
        if(n%2 == 1)
            cout << n/2+1+m-n << " " << n/2+1;
        
        else
            cout << n/2+1 << " " << n/2;
    }
    
    else {
        if(m%2 == 1)
            cout << m/2+1 << " " << m/2+1+n-m;
        
        else
            cout << m/2+1 << " " << m/2;
    }
    
    return 0;
}