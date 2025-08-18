#include <iostream>

using namespace std;

int main() {
    string a, b;
    string result = "";
    int i = 0;
    int c = 0;
    
    cin >> a >> b;
    
    while(i<a.size() || i<b.size()) {
        int an=0, bn=0;
        
        if(i < a.size())
            an = a[a.size()-i-1] - '0';
        
        if(i < b.size())
            bn = b[b.size()-i-1] - '0';
        
        char cc = (an + bn + c) % 2 + '0';
        
        result = cc + result;
        
        c = (an + bn + c) / 2;
        
        i++;
    }
    
    if(c != 0)
        result = "1" + result;
    
    bool state = true;
    
    for(int i=0; i<result.size(); i++) {
        if(state) {
            if(result[i] == '1') {
                state = false;
                cout << result[i];
            }
        }
        else {
            cout << result[i];
        }
    }
    
    if(state)
        cout << 0;
    
    return 0;
}