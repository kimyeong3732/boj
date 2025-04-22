#include <iostream>

using namespace std;

int main() {
    int a, b;
    int n = 0;
    int max = 0;
    
    for(int i=0; i<4; i++) {
        cin >> a >> b;
        
        n += b - a;
        
        if(max < n)
            max = n;
    }
    
    cout << max;
    
    return 0;
}