#include <iostream>

using namespace std;

int main() {
    int n;
    int state = -1;
    int q;
    int nums[3];
    
    cin >> n;
    
    for(int i=0; i<3; i++) {
        cin >> nums[i];
    }
    
    if((nums[1]-nums[0]) == (nums[2]-nums[1])) {
        state = 0;
        q = nums[1] - nums[0];
    }
    
    else {
        state = 1;
        q = nums[1] / nums[0];
    }
    
    int last = nums[2];
    
    for(int i=3; i<n; i++)
        cin >> last;
    
    if(state == 0)
        cout << last + q;
    
    else
        cout << last * q;
    
    return 0;
}