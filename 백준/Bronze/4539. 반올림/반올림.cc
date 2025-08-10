#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        int t = 10;
        
        while(t <= num) {
            int m = num / t;
            int r = num % t;
            
            if(r >= t/2)
                m++;
            
            num = m * t;
            
            t *= 10;
        }
        
        cout << num << "\n";
    }
    
    return 0;
}