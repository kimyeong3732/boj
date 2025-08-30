#include <iostream>

using namespace std;

int main() {
    int n;
    int result = 1;
    
    cin >> n;
    
    int l=1, r=2;
    int sum = 3;
    
    while(l<r && r<n ) {
        if(sum > n) {
            sum -= l;
            l++;
        }
        else {
            if(sum == n)
                result++;
            
            r++;
            sum += r;
        }
    }
    
    cout << result;
    
    return 0;
}