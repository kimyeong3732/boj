#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    for(int t=0; t<n; t++) {
        int result[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        string s;
        
        cin >> s;
        
        for(int i=0; i<38; i++ ){
            int d = 0;
            
            for(int j=0; j<3; j++) {
                if(s[i+j] == 'H') {
                    int dd = 4;
                    
                    for(int k=0; k<j; k++) {
                        dd /= 2;
                    }
                    
                    d += dd;
                }
            }
            
            result[d]++;
        }
        
        for(int i=0; i<8; i++) {
            cout << result[i] << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}