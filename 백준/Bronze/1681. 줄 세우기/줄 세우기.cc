#include <iostream>

using namespace std;

int main() {
    int n, l;
    
    cin >> n >> l;
    
    int result = 0;
    
    for(int i=0; i<n; i++) {
        while(true) {
            result++;
            
            int state = 0;
            int temp = result;
            
            while(temp > 0) {
                if(temp%10 == l) {
                    state = 1;
                    break;
                }
                
                temp /= 10;
            }
            
            if(state == 0) {
                break;
            }
        }
    }
    
    cout << result;
    
    return 0;
}