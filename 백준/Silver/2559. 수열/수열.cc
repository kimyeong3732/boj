#include <iostream>

using namespace std;

int main() {
    int n, k;
    int max = -10000001;
    int sum = 0;
    int now = 0;
    int nums[100000];
    
    cin >> n >> k;
    
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        
        sum += nums[i];
        
        if(i >= k) {
            sum -= nums[i-k];
        }
        
        if(i>=k-1 && sum>max) {
            max = sum;
        }
    }
    
    cout << max;
    
    return 0;
}