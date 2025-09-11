#include <iostream>

using namespace std;

int main() {
    int n, s;
    int nums[100];
    
    cin >> n >> s;
    
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    int r = 0;
    
    while(s <= nums[r]) {
        s++;
        r = (r + 1) % n;
    }
    
    cout << r + 1;
    
    return 0;
}