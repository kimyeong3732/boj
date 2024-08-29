#include<iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        int result = 1;
    
        cin >> a >> b;
    
        for(int j=0; j<b; j++) {
            result *= a;
            result %= 10;
        }
    
        if(result == 0) {
            result = 10;
        }
    
        cout << result << "\n";
    }
    
    return 0;
}