#include <iostream>

using namespace std;

int main() {
    int r[2] = {0, 0};
    
    for(int i=0; i<9; i++) {
        string temp;
        
        cin >> temp;
        
        if(temp[0] == 'L')
            r[0]++;
        else
            r[1]++;
    }
    
    if(r[0] > r[1])
        cout << "Lion";
    else
        cout << "Tiger";
    
    return 0;
}