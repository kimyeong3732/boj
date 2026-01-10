#include <iostream>

using namespace std;

int main() {
    long long n;
    bool state = true;
    
    cin >> n;
    
    long long l=1, r=2;
    
    while(l < r) {
        long long m = r * r - l * l;
        
        if(m <= n) {
            if(m == n) {
                if(state)
                    state = false;
                
                cout << r << "\n";
            }
            
            r++;
        }
        
        else {
            l++;
        }
    }
    
    if(state)
        cout << -1;

    return 0;
}