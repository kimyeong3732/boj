#include <iostream>

using namespace std;

int main() {
    int h1, h2, m1, m2, s1, s2;
    int hr, mr, sr;
    char c;
    
    cin >> h1 >> c >> m1 >> c >> s1;
    cin >> h2 >> c >> m2 >> c >> s2;
    
    if(h2 < h1)
        h2 += 24;
    
    hr = h2 - h1;
    
    if(m2 < m1) {
        hr--;
        m2 += 60;
    }
    
    mr = m2 - m1;
    
    if(s2 < s1) {
        if(mr == 0) {
            if(hr == 0)
                hr += 24;
            
            hr--;
            mr += 60;
        }
        
        mr--;
        s2 += 60;
    }
    
    sr = s2 - s1;
    
    if(hr==mr && mr==sr && hr==0)
        hr += 24;
    
    if(hr < 10)
        cout << 0;
    
    cout << hr << ":";
    
    if(mr < 10)
        cout << 0;
    
    cout << mr << ":";
    
    if(sr < 10) 
        cout << 0;
    
    cout << sr;
    
    return 0;
}