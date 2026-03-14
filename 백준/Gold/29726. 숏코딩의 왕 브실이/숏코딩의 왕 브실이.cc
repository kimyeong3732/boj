#include <iostream>

using namespace std;

int main() {
    int n, k;
    int input[200000];
    
    cin >> n >> k;
    
    for(int i=0; i<n; i++)
        cin >> input[i];
    
    int result = -100000;
    
    int mn = input[0];
    
    for(int j=n-k-1; j<n; j++) {
        mn = min(mn, input[j-n+k+1]);
        
        result = max(result, input[j]-mn);
    }
    
    cout << result;
    
    return 0;
}