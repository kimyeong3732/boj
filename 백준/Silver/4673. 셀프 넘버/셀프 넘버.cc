#include <iostream>

using namespace std;

bool nums[10001];

int main() {
    for(int i=1; i<10000; i++) {
        int temp = i;
        int sum = i;
        
        while(temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        
        if(!nums[sum]) {
            nums[sum] = true;
        }
    }
    
    for(int i=1; i<10001; i++) {
        if(!nums[i]) {
            cout << i << "\n";
        }
    }
    
    return 0;
}