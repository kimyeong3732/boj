#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int tens = 10;
    
    while(n/tens != 0) {
        int a = n / tens;
        int b = n % tens / (tens / 10);
        
        if(b >= 5) {
            a++;
        }
        
        n = a * tens;
        
        tens *= 10;
    }
    
    cout << n;
    
    return 0;
}