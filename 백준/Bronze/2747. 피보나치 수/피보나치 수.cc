#include <iostream>

using namespace std;

int main() {
    int n;
    int nums[46];
    
    nums[0] = 0;
    nums[1] = 1;
    
    cin >> n;
    
    for(int i=2; i<=n; i++)
        nums[i] = nums[i-1] + nums[i-2];
    
    cout << nums[n];
    
    return 0;
}