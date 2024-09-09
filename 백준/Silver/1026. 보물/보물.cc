#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int a[50];
    int b[50];
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }
    
    sort(a, a+n);
    sort(b, b+n, greater<int>());
    
    int result = 0;
    
    for(int i=0; i<n; i++) {
        result += a[i] * b[i];
    }
    
    cout << result;
    
    return 0;
}