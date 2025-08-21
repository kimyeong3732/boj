#include <iostream>

using namespace std;

int main() {
    string a, b;
    
    cin >> a >> b;
    
    if(a.size() != b.size()) {
        cout << 0;
    }
    
    else {
        int result = 0;
        
        for(int i=0; i<a.size(); i++) {
            if(a[i] != b[i])
                break;
            
            if(a[i] == '8')
                result++;
        }
        
        cout << result;
    }
    
    return 0;
}