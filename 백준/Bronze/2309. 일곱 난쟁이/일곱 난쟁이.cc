#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int h[9];
    int sum = 0;
    
    for(int i=0; i<9; i++) {
        cin >> h[i];
        sum += h[i];
    }
    
    sort(h, h+9);
    
    bool state = false;
    
    for(int i=0; i<8; i++) {
        sum -= h[i];
        
        for(int j=i+1; j<9; j++) {
            sum -= h[j];
            
            if(sum < 100) {
                sum += h[j];
                break;
            }
            else if(sum == 100) {
                for(int k=0; k<9; k++)
                    if(k!=i && k!=j)
                        cout << h[k] << "\n";
                
                state = true;
            }
            
            sum += h[j];
        }
        
        if(state)
            break;
        
        sum += h[i];
    }
    
    return 0;
}