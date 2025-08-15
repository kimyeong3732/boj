#include <iostream>

using namespace std;

int main() {
    int result[1000001];
    
    result[1] = 1;
    result[2] = 2;
    
    int n;
    
    cin >> n;
    
    for(int i=3; i<=n; i++)
        result[i] = (result[i-2] + result[i-1]) % 15746;
    
    cout << result[n];
    
    return 0;
}