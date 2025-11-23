#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    cin >> a >> b;
    
    if(a < b) {
        int diff = b - a;
        
        if(diff <= 20)
            cout << "You are speeding and your fine is $100.";
        else if(diff <= 30)
            cout << "You are speeding and your fine is $270.";
        else
            cout << "You are speeding and your fine is $500.";
    }
    else {
        cout << "Congratulations, you are within the speed limit!";
    }
    
    return 0;
}