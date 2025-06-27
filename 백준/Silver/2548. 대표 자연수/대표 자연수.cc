#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int nums[20000];
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    sort(nums, nums+n);
    
    int result = 0;
    int sum = -1;
    
    for(int i=0; i<n; i++) {
        int temp = 0;
        
        for(int j=0; j<n; j++) {
            if(i < j)
                temp += nums[j] - nums[i];
            else
                temp += nums[i] - nums[j];
        }
        
        if(sum<0 || temp<sum) {
            result = nums[i];
            sum = temp;
        }
    }
    
    cout << result;
    
    return 0;
}