#include <iostream>

using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        long long n;
        long long rest = 0;
        
        cin >> n;
        
        for(long long j=0; j<n; j++) {
            long long num;
            
            cin >> num;
            
            rest = (num + rest) % n;
        }
        
        if(rest != 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    
    return 0;
}