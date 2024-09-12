#include <iostream>

using namespace std;

int main() {
    int n, l;
    int s = -1;
    int e = -1;
    
    cin >> n >> l;
    
    for(int i=l; i<=100; i++) {
        if(i%2==0 && n%i==i/2) {
            s = (n / i) - (i / 2) + 1;
            e = (n / i) + (i / 2);
        }
        if(i%2!=0 && n%i==0) {
            s = (n / i) - (i / 2);
            e = (n / i) + (i / 2);
        }
        
        if(s >= 0) {
            break;
        }
        
        s = -1;
        e = -1;
    }
    
    for(int i=s; i<=e; i++) {
        cout << i << " ";
    }
    
    return 0;
}