#include <iostream>

using namespace std;

int main() {
    char alpha[64] = {'A', 'A', 'A', 'C', 'A', 'Z', 'E', 'B',
                      'A', 'F', 'Z', 'B', 'D', 'B', 'B', 'B',
                      'A', 'C', 'C', 'C', 'D', 'G', 'Z', 'C',
                      'D', 'Z', 'H', 'C', 'D', 'D', 'D', 'B',
                      'A', 'F', 'E', 'Z', 'E', 'G', 'E', 'E',
                      'F', 'F', 'H', 'F', 'Z', 'F', 'E', 'B',
                      'Z', 'G', 'H', 'C', 'G', 'G', 'E', 'G',
                      'H', 'F', 'H', 'H', 'D', 'G', 'H', 'Z'};
    
    int n;
    string m;
    string result = "";
    bool state = true;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        int num = 0;
        
        for(int j=0; j<6; j++) {
            num *= 2;
            
            num += m[i*6+j] - '0';
        }
        
        if(alpha[num] == 'Z') {
            cout << i+1;
            state = false;
            break;
        }
        
        result += alpha[num];
    }
    
    if(state)
        cout << result;
    
    return 0;
}