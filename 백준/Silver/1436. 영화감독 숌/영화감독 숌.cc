#include <iostream>
using namespace std;

int main() {
    int n, num = 665;
    
    cin >> n;
    
    while(n > 0) {
        num++;
        int temp = num;
        
        while(temp > 66) {
            if((temp%1000) == 666) {
                n--;
                break;
            }
            temp /= 10;
        }
    }
    
    cout << num << endl;
    
    return 0;
}