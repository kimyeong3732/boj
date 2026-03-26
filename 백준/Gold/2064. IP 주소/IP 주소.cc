#include <iostream>

using namespace std;

int main() {
    int n;
    long long input[1000];
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        long long num;
        char p;
        
        cin >> input[i];
        
        for(int j=0; j<3; j++) {
            cin >> p >> num;
            
            input[i] *= 256;
            input[i] += num;
        }
    }
    
    long long mask = 0;
    
    for(int i=31; i>=0; i--) {
        long long bit = (long long)1 << i;
        bool state = false;
        
        for(int j=1; j<n; j++) {
            if((input[0]&bit) != (input[j]&bit)) {
                state = true;
                break;
            }
        }
        
        if(state)
            break;
        
        mask += bit;
    }
    
    long long net = input[0] & mask;
    
    long long resultnet[4];
    long long resultmask[4];
    
    for(int i=3; i>=0; i--) {
        resultnet[i] = net % 256;
        net /= 256;
        
        resultmask[i] = mask % 256;
        mask /= 256;
    }
    
    for(int i=0; i<4; i++) {
        cout << resultnet[i];
        
        if(i == 3)
            cout << "\n";
        
        else
            cout << ".";
    }
    
    for(int i=0; i<4; i++) {
        cout << resultmask[i];
        
        if(i == 3)
            cout << "\n";
        
        else
            cout << ".";
    }
    
    return 0;
}