#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string nums;
    
    cin >> nums;
    
    sort(&nums[0], &nums[nums.size()], greater<>());
    
    cout << nums;
    
    return 0;
}