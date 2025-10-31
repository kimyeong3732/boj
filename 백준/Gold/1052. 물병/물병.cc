#include <iostream>

using namespace std;

int main() {
    int n, m;
    
    cin >> n >> m;
    
    int on = 0;
    string t = "";
    
    while(n > 0) {
        if(n%2 == 1)
            on++;
        
        t += n%2 + '0';
        n /= 2;
    }
    
    int r = 0;
    int c = 1;
    int i = 0;
    
    while(i < t.size()) {
        if(on <= m)
            break;
        
        if(t[i] == '1') {
            r += c;
            on--;
            t[i] = '0';
            
            int j = i + 1;
            
            while(j<t.size() && t[j] == '1') {
                on--;
                t[j] = '0';
                j++;
            }
            
            if(j == t.size()) {
                on++;
                t += '1';
            }
            else {
                on++;
                t[j] = '1';
            }
        }
        
        c *= 2;
        i++;
    }
    
    cout << r;
    
    return 0;
}