#include <iostream>

using namespace std;

int main() {
    int m, n;
    
    cin >> m >> n;
    
    int sum = 0;
    int min = -1;
    int i = 1;
    
    while(true) {
        int num = i * i;
        
        if(num > n) {
            break;
        }
        else if(num>=m) {
            sum += num;
            
            if(min < 0) {
                min = num;
            }
        }
        
        i++;
    }
    
    if(min > 0)
        cout <<  sum << "\n";
    
    cout << min;
    
    return 0;
}