#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    cin >> a >> b;
    
    int ax=0, an=0;
    int bx=0, bn=0;
    
    int c = 1;
    
    while(a > 0) {
        int temp = a % 10;
        
        if(temp==5 || temp==6) {
            ax += 6 * c;
            an += 5 * c;
        }
        else {
            ax += temp * c;
            an += temp * c;
        }
        
        a /= 10;
        c *= 10;
    }
    
    c = 1;
    
    while(b > 0) {
        int temp = b % 10;
        
        if(temp==5 || temp==6) {
            bx += 6 * c;
            bn += 5 * c;
        }
        else {
            bx += temp * c;
            bn += temp * c;
        }
        
        b /= 10;
        c *= 10;
    }
    
    cout << an+bn << " " << ax+bx;
    
    return 0;
}