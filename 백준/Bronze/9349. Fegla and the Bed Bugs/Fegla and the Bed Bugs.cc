#include <iostream>

using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int n, k;
        
        cin >> n >> k;
        
        int r = n - k;
        
        r /= k - 1;
        
        cout << r << "\n";
    }
    
    return 0;
}