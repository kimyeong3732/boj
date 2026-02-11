#include <iostream>

using namespace std;

int main() {
    long long k;
    string result = "";
    
    cin >> k;
    
    long long c = 1;
    
    while(k >= c) {
        k -= c;
        c *= 2;
    }
    
    for(c/=2; c>0; c/=2) {
        if(k/c == 0)
            result += "4";
        
        else
            result += "7";
        
        k %= c;
    }
    
    cout << result;
    
    return 0;
}