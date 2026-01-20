#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int nums[1000];
    vector<int> sums;
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            sums.push_back(nums[i] + nums[j]);
    
    sort(nums, nums+n);
    sort(sums.begin(), sums.end());
    
    bool state = false;
    
    for(int i=n-1; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            int temp = nums[i] - nums[j];
            
            int index = lower_bound(sums.begin(), sums.end(), temp) - sums.begin();
            
            if(temp == sums[index]) {
                cout << nums[i];
                state = true;
                break;
            }
        }
        
        if(state)
            break;
    }
    
    return 0;
}