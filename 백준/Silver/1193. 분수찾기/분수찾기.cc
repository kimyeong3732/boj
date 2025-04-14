#include <iostream>

using namespace std;

int main() {
    int n, i=1;
    int num = 0;
    
    cin >> n;
    
    while(num < n) {
        num += i;
        i++;
    }
    num -= i - 1;
    
    if(i%2==1)
        cout << n-num << "/" << i-n+num;
    else
        cout << i-n+num << "/" << n-num;
    
    return 0;
}