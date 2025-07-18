#include <iostream>

using namespace std;

int main() {
    int c, k;
    
    while(true) {
        cin >> c >> k;
        
        if(cin.eof())
            break;
        
        int rest=c, result=c;
        
        while(rest >= k) {
            int temp = rest / k;
            result += temp;
            rest %= k;
            rest += temp;
        }
        
        cout << result << "\n";
    }
    
    return 0;
}