#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        long long x, y;
        cin >> x >> y;

        long long d = y - x;

        long long m = sqrt(d);
        
        d -= m * m;
        
        if(d > m)
            cout << 2 * m + 1;
        
        else if(d > 0)
            cout << 2 * m;
        
        else
            cout << 2 * m - 1;
        
        cout << "\n";
    }
    
    return 0;
}