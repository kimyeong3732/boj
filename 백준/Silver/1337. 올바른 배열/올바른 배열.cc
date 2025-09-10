#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int nums[50];
    
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    sort(nums, nums+n);
    
    int m = 1;
    int l=0, r=1;
    
    while(r<n && l<=r) {
        int temp = nums[r] - nums[l];
        
        if(temp > 4) {
            int c = r - l;
            
            if(m < c)
                m = c;
            
            l++;
        }
        else {
            r++;
        }
    }
    
    int c = r - l;
    
    if(m < c)
        m = c;
    
    if(m > 5)
        m = 5;
    
    cout << 5 - m;
    
    return 0;
}