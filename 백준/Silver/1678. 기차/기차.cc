#include <iostream>

using namespace std;

string ss[60];
bool bs[60];

int main() {
    int t, m, n;
    int nn = 0;
    
    cin >> t >> m >> n;
    
    for(int i=0; i<t; i++) {
        int num;
        string s;
        
        cin >> s;
        
        cin >> num;
        
        while(num > 0) {
            if(num < m)
                num += 60;
            num -= m;
            
            ss[num] = s;
            bs[num] = true;
            nn++;
            
            cin >> num;
        }
    }
        
    int nr = (n - 1) % nn;
    
    for(int i=0; i<60; i++) {
        if(bs[i]) {
            if(nr == 0) {
                cout << ss[i];
                break;
            }
            
            nr--;
        }
    }
    
    return 0;
}