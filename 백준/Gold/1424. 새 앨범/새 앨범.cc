#include <iostream>

using namespace std;

int main() {
    int n, l, c;
    
    cin >> n >> l >> c;
    
    int r = (c + 1) / (l + 1);
    
    if(n < r)
        r = n;
    
    if(r%13 == 0)
        r--;
    
    int result = (n + r - 1) / r;
    
    int rr = n % r;
    
    if(rr!= 0 && rr%13==0 && r-rr==1)
        result++;
    
    cout << result;
    
    return 0;
}