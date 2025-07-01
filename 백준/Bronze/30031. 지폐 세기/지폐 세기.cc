#include <iostream>

using namespace std;

int main() {
    int n;
    int result = 0;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int w, h;
        
        cin >> w >> h;
        
        if(w == 136)
            result += 1000;
        else if(w == 142)
            result += 5000;
        else if(w == 148)
            result += 10000;
        else
            result += 50000;
    }
    
    cout << result;
    
    return 0;
}