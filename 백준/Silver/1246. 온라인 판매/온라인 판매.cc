#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    int nums[1000];
    int p = 0;
    int sum = 0;
    
    cin >> n >> m;
    
    for(int i=0; i<m; i++)
        cin >> nums[i];
    
    sort(nums, nums+m);
    
    for(int i=0; i<m; i++) {
        int temp = nums[i] * min(m-i, n);
        
        if(sum < temp) {
            sum = temp;
            p = nums[i];
        }
    }
    
    cout << p << " " << sum;
    
    return 0;
}