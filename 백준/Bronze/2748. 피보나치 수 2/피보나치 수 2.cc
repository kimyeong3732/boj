#include <iostream>

using namespace std;

int main() {
    long long pivots[91] = {0, 1, };
    
    for(int i=2; i<91; i++) {
        pivots[i] = pivots[i-2] + pivots[i-1];
    }
    
    int n;
    
    cin >> n;
    
    cout << pivots[n];
    
    return 0;
}