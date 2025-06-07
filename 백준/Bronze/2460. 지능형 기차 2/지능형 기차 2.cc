#include <iostream>

using namespace std;

int main() {
    int peoples = 0;
    int result = 0;
    
    for(int i=0; i<10; i++) {
        int a, b;
        
        cin >> a >> b;
        
        peoples += b - a;
        
        if(peoples > result)
            result = peoples;
    }
    
    cout << result;
    
    return 0;
}