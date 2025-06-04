#include <iostream>

using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int num;
        
        cin >> num;
        
        cout << num/25 << " ";
        num %= 25;
        
        cout << num/10 << " ";
        num %= 10;
        
        cout << num/5 << " " << num%5 << "\n";
    }
    
    return 0;
}