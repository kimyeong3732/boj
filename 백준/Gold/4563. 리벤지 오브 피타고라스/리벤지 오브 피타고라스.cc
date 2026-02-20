#include <iostream>

using namespace std;

int main() {
    long long a;
    
    cin >> a;
    
    while(a > 0) {
        long long c = 0;
        long long pa = a * a;
        
        for(long long i=1; i<a-1; i++) {
            if(pa%i == 0) {
                long long b2 = pa/i - i;
                
                if(b2%2==0 && b2/2>a)
                    c++;
            }
        }
        
        cout << c << "\n";
        
        cin >> a;
    }
    
    return 0;
}