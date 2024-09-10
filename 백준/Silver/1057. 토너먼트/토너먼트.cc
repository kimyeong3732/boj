#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    int result = 0;
    
    cin >> n >> a >> b;
    
    while(a!=b && n!=1) {
        n = (n+1) / 2;
        a = (a+1) / 2;
        b = (b+1) / 2;
        result++;
    }
    
    if(n==1 && a!=b) {
        result = -1;
    }
    
    cout << result;
    
    return 0;
}