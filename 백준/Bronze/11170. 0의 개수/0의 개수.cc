#include <iostream>

using namespace std;

int check(int a) {
    int n = a;
    
    if(n == 0)
        return 1;
    
    int r = 0;
    
    while(n > 0) {
        if(n%10 == 0)
            r++;
        
        n /= 10;
    }
    
    return r;
}

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int a, b;
        int r = 0;
        
        cin >> a >> b;
        
        for(int j=a; j<=b; j++)
            r += check(j);
        
        cout << r << "\n";
    }
    
    return 0;
}