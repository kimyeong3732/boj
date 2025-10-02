#include <iostream>

using namespace std;

int main() {
    int t = 0;
    int a, b, c, d;
    
    cin >> a >> b >> c >> d;
    
    while(a>=0 && b>=0 && c>=0 && d>=0) {
        t++;
        
        for(int i=d+1; i<=21252; i++) {
            if(i%23==a%23 && i%28==b%28 && i%33==c%33) {
                cout << "Case " << t << ": the next triple peak occurs in " << i-d << " days.\n";
                break;
            }
        }
        
        cin >> a >> b >> c >> d;
    }
    
    return 0;
}