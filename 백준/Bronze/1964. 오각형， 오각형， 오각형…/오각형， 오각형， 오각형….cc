#include <iostream>

using namespace std;

int main() {
    int result = 1;
    int k = 4;
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        result += k;
        result %= 45678;
        k += 3;
    }
    
    cout << result;
    
    return 0;
}