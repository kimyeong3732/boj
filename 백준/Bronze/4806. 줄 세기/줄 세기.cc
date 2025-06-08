#include <iostream>

using namespace std;

int main() {
    int result = 0;
    
    string s;
    while(getline(cin, s))
 	    result++;
    
    cout << result;
    
    return 0;
}