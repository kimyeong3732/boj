#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int v, e;
        
        cin >> v >> e;
        
        cout << e + 2 - v << "\n";
    }
    
    return 0;
}