#include <iostream>

using namespace std;

int main() {
    int level;
    
    cin >> level;
    
    while(level > 0) {
        int result = 1;
        
        for(int i=0; i<level; i++) {
            int mul, sub;
            
            cin >> mul >> sub;
            
            result = result * mul - sub;
        }
        
        cout << result << "\n";
        
        cin >> level;
    }
    
    return 0;
}