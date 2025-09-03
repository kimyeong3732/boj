#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int nums[50];
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a, b;
        
        cin >> a >> b;
        
        nums[i] = a - b;
    }
    
    sort(nums, nums+n);
    
    if(n%2 == 1)
        cout << 1;
    else
        cout << nums[n/2] - nums[n/2-1] + 1;
    
    return 0;
}