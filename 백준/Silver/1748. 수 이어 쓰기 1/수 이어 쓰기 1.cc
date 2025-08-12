#include <iostream>

using namespace std;

int main() {
    int num;
    int result = 0;
    
    cin >> num;
    
    int current = 1;
    
    for(int i=1; current<=num; i++) {
        if(num >= current*10)
            result += i * (current * 10 - current);
        else
            result += i * (num - current + 1);
        
        current *= 10;
    }
    
    cout << result;
    
    return 0;
}