#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int s = 2;
    
    if(n == 3) {
        cout << -1;
    }
    
    else {
        for(int i=1; i<=n; i++) {
            if(i == n/2) {
                cout << "1\n" << n << "\n";
                i += 2;
            }
            
            cout << s << "\n";
            s++;
        }
    }
    
    return 0;
}