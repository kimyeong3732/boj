#include <iostream>

using namespace std;

int nums[900];

int main() {
    int sum = 0;
    
    for(int i=0; i<10; i++) {
        int temp;
        
        cin >> temp;
        
        sum += temp;
        
        nums[temp/10-1]++;
    }
    
    int max = 0;
    int result = 0;
    
    for(int i=0; i<900; i++) {
        if(max < nums[i]) {
            max = nums[i];
            result = (i + 1) * 10;
        }
    }
    
    cout << sum/10 << "\n" << result;
    
    return 0;
}