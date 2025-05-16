#include <iostream>

using namespace std;

int main() {
    int n, k;
    int nums[20];
    
    cin >> n >> k;
    
    for(int i=0; i<n-1; i++) {
        char c;
        
        cin >> nums[i] >> c;
    }
    
    cin >> nums[n-1];
    
    for(int i=0; i<k; i++) {
        for(int j=0; j<n-i-1; j++) {
            nums[j] = nums[j+1] - nums[j];
        }
    }
    
    for(int i=0; i<n-k-1; i++) {
        cout << nums[i] << ",";
    }
    
    cout << nums[n-k-1];
    
    return 0;
}