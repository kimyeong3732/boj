#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    cin >> a >> b;
    
    if(b <= 2)
        cout << "NEWBIE!";
    else if(b <= a)
        cout << "OLDBIE!";
    else
        cout << "TLE!";
    
    return 0;
}