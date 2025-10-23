#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int nt;
        char ct;
        int num;
        
        cin >> nt >> ct >> num;
        
        v.push_back(nt * 1000 + num);
    }
    
    for(int i=1; i<=1000; i++) {
        bool state1 = true;
        
        for(int j=0; j<v.size(); j++) {
            bool state2 = false;
            
            for(int k=0; k<=10*i; k++) {
                int num = k * 1000 / i;
                
                if(v[j] == num) {
                    state2 = true;
                    break;
                }
            }
            
            if(!state2) {
                state1 = false;
                break;
            }
        }
        
        if(state1) {
            cout << i;
            break;
        }
    }
    
    return 0;
}