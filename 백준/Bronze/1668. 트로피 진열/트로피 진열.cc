#include <iostream>

using namespace std;

int main() {
    int n;
    int l=0, r=0;
    int nums[50];
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    int max = 0;
    
    for(int i=0; i<n; i++) {
        if(max < nums[i]) {
            max = nums[i];
            l++;
        }
    }
    
    max = 0;
    
    for(int i=n-1; i>=0; i--) {
        if(max < nums[i]) {
            max = nums[i];
            r++;
        }
    }
    
    cout << l << "\n" << r;
    
    return 0;
}