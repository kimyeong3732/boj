#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    int nums[1000];
    
    cin >> n >> l;
    
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    sort(nums, nums+n);
  
    int result = 0;
    int current = -1;
    
    for(int i=0; i<n; i++) {
        if(current < nums[i]) {
            current = nums[i] - 1 + l;
            result++;
        }
    }
    
    cout << result;
    
    return 0;
}