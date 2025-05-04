#include <iostream>

using namespace std;

int main() {
    string input;
    
    getline(cin, input);
    
    while(input.compare("END") != 0) {
        for(int i=input.size()-1; i>=0; i--) {
            cout << input[i];
        }
        cout << "\n";
        
        getline(cin, input);
    }
    
    return 0;
}