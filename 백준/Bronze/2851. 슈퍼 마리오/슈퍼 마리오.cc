#include <iostream>

using namespace std;

int main() {
    int nums[10];
    
    for(int i=0; i<10; i++) {
        cin >> nums[i];
    }
    
    int result = 0;
    
    for(int i=0; i<10; i++) {
        result += nums[i];
        
        if(result >= 100) {
            if((100-result+nums[i]) < (result-100))
                result -= nums[i];
            break;
        }
    }
    
    cout << result;
    
    return 0;
}