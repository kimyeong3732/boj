#include <iostream>

using namespace std;

int main() {
    int n, l, d;
    
    cin >> n >> l >> d;
    
    int time1 = 0;
    int time2 = 0;
    
    for(int i=0; i<n; i++) {
        time1 += l;
        
        int state = 0;
        
        while(time2 < time1) {
            state = 1;
            time2 += d;
        }
        
        if(time1<=time2 && time2<=(time1+4))
            break;
        
        time1 += 5;
    }
    
    cout << time2;
    
    return 0;
}