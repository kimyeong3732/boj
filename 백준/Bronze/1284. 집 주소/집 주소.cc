#include <iostream>

using namespace std;

int main() {
    int n;
    int result = 1;
    
    cin >> n;
    
    while(n != 0) {
        while(n > 0) {
            int temp = n % 10;
            
            if(temp == 1)
                result += 3;
            else if(temp == 0)
                result += 5;
            else
                result += 4;
            
            n /= 10;
        }
        cout << result << "\n";
        
        result = 1;
        
        cin >> n;
    }
    
    return 0;
}