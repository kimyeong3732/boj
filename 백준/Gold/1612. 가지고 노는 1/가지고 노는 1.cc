#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    if(n%10==0 || n%10==2 || n%10==4 || n%10==5 || n%10==6 || n%10==8) {
        cout << -1;
    }
    else {
        int r = 1;
        int num = 1;
        
        while(num%n != 0) {
            num %= n;
            num *= 10;
            num++;
            
            r++;
        }
        
        cout << r;
    }
    
    return 0;
}