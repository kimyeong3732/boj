#include <iostream>

using namespace std;

int main() {
    int s, m;
    
    cin >> s >> m;
    
    int a = s + m;
    
    if(a%2 != 0)
        cout << -1;
    else {
        a /= 2;
        int b = s - a;
        
        if(b < 0)
            cout << -1;
        else
            cout << a << " " << b;
    }
    
    return 0;
}