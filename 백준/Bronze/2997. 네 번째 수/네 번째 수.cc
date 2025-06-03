#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int nums[3];
    
    for(int i=0; i<3; i++)
        cin >> nums[i];
    
    sort(nums, nums+3);
    
    int diff = 200;
    
    for(int i=1; i<3; i++)
        if(nums[i]-nums[i-1] < diff)
            diff = nums[i] - nums[i-1];
    
    int result = -101;
    
    for(int i=1; i<3; i++)
        if(nums[i]-nums[i-1] != diff)
            result = nums[i] - diff;
    
    if(result == -101)
        result = nums[2] + diff;
    
    cout << result;
    
    return 0;
}