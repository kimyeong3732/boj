#include <iostream>

using namespace std;

int main() {
    string a, b;
    
    cin >> a >> b;
    
    int result = 50;
    int al = a. length();
    int diff = b.length() - al;
    
    for(int i=0; i<=diff; i++) {
        int sub_result = 0;
        for(int j=0; j<al; j++) {
            if(a[j] != b[i+j]) {
                sub_result++;
            }
        }
        
        if(result > sub_result) {
            result = sub_result;
        }
    }
    
    cout << result;
    
    return 0;
}