#include <iostream>

using namespace std;

int main() {
    string color[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    
    long result = 0;
    
    for(int i=0; i<3; i++) {
        string input;
        cin >> input;
        
        if(i < 2) {
            result *= 10;
            for(int j=0; j<10; j++) {
                if(input.compare(color[j]) == 0) {
                    result += j;
                    break;
                }
            }
        }
        else {
            for(int j=0; j<10; j++) {
                if(input.compare(color[j]) == 0) {
                    for(int k=0; k<j; k++) {
                        result *= 10;
                    }
                    break;
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}