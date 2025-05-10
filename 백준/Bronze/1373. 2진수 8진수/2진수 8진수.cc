#include <iostream>

using namespace std;

int main() {
    string two;
    
    cin >> two;
    
    int state = (3 - (two.size() % 3)) % 3;
    int num = 0;
    
    for(int i=0; i<two.size(); i++) {
        if(state == 3) {
            cout << num;
            num = 0;
            state = 0;
        }
        
        num *= 2;
        num += two[i] - '0';
        state++;
    }
    
    cout << num;
    
    return 0;
}