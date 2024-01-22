#include <iostream>
using namespace std;

int find(int num) {
    int count = 0;
    
    if(num > 2) {
        count += find(num - 3);
    }
    if(num > 1) {
        count += find(num - 2);
    }
    if(num > 0) {
        count += find(num - 1);
    }
    if(num == 0)
        return 1;
    
    return count;
}

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int num;
        cin >> num;
        
        cout << find(num) << endl;
    }
    
    return 0;
}