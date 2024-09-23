#include <iostream>

using namespace std;

int main() {
    int target;
    
    cin >> target;
    
    int result = 0;
    
    while(target > 0) {
        int stick = 64;
        
        while(target < stick) {
            stick /= 2;
        }
        
        target -= stick;
        result++;
    }
    
    cout << result;
    
    return 0;
}