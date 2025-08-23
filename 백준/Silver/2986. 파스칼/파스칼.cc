#include <iostream>

using namespace std;

int main() {
    int n;
    
    bool state = true;
    
    cin >> n;
    
    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) {
            int temp = n / i;
            state = false;
            
            cout << n - temp;
            
            break;
        }
    }
    
    if(state)
        cout << n - 1;
    
    return 0;
}