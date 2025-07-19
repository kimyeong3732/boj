#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string s;
        
        cin >> s;
        
        int num1=0, num2=0;
        
        for(int j=0; j<3; j++) {
            num1 *= 26;
            num1 += s[j] - 'A';
        }
        
        for(int j=4; j<8; j++) {
            num2 *= 10;
            num2 += s[j] - '0';
        }
        
        if(num1-num2<-100 || num1-num2>100)
            cout << "not ";
        
        cout << "nice\n";
    }
    
    return 0;
}