#include <iostream>

using namespace std;

int main() {
    int nums[5];
    
    for(int i=0; i<5; i++)
        cin >> nums[i];
    
    int state = 1;
    
    while(state > 0) {
        state = 0;
        
        for(int i=0; i<4; i++) {
            if(nums[i] > nums[i+1]) {
                state = 1;
                
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
                
                for(int i=0; i<5; i++)
                    cout << nums[i] << " ";
                cout << "\n";
            }
        }
    }
    
    return 0;
}