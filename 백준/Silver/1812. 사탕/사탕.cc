#include <iostream>

using namespace std;

int main() {
    int n;
    int candies[1000];
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> candies[i];
    }
    
    int a = candies[0];
    int status = -1;
    
    for(int i=1; i<n; i++) {
        a += candies[i] * status;
        status *= -1;
    }
    
    a /= 2;
    cout << a << "\n";
    for(int i=0; i<n-1; i++) {
        cout << candies[i] - a << "\n";
        a = candies[i] - a;
    }
    
    return 0;
}