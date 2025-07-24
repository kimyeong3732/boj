#include <iostream>

using namespace std;

int main() {
    int a, b;
    char c;
    
    cin >> c >> a >> c >> b;
    
    while(a!=0 && b!=0) {
        char temp[7];
        int i = 0;
        
        while(b > 0) {
            b--;
            temp[i] = (b % 26) + 'A';
            i++;
            b /= 26;
        }
        
        for(i=i-1; i>=0; i--)
            cout << temp[i];
        
        cout << a << "\n";
        cin >> c >> a >> c >> b;
    }
    
    return 0;
}