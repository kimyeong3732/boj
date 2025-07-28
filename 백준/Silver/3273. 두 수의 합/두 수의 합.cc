#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, num;
    int result = 0;
    int l, r;
    int nums[100000];
    
    cin >> n;
    l = 0;
    r = n - 1;
    
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    cin >> num;
    
    sort(nums, nums+n);
    
    while(l < r) {
        if(nums[l]+nums[r] > num) {
            r--;
        }
        else {
            if(nums[l]+nums[r] == num)
                result++;
            l++;
        }
    }
    
    cout << result;
    
    return 0;
}