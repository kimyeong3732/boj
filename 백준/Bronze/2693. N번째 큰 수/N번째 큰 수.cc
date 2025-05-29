#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int nums[10];
        
        for(int j=0; j<10; j++) {
            cin >> nums[j];
        }
        
        sort(nums, nums+10);
        
        cout << nums[7] << "\n";
    }
    
    return 0;
}