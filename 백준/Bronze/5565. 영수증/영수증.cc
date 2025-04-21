#include <iostream>

using namespace std;

int main() {
    int total;
    int sum = 0;
    
    cin >> total;
    
    for(int i=0; i<9; i++) {
        int temp;
        
        cin >> temp;
        
        sum += temp;
    }
    
    cout << total-sum;
    
    return 0;
}