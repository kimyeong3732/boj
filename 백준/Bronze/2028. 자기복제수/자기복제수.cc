#include <iostream>

using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int num;
        
        cin >> num;
        
        int result = num * num;
        
        if(num < 10)
            result %= 10;
        else if(num < 100)
            result %= 100;
        else if(num < 1000)
            result %= 1000;
        else
            result %= 10000;
        
        if(result == num)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}