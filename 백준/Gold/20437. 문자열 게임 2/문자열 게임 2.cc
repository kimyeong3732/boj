#include <iostream>

using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        string s;
        int n;
        int rn = 10000;
        int rx = -1;
        
        cin >> s >> n;
        
        if(n == 1) {
            cout << 1 << " " << 1 << "\n";
            
            continue;
        }
        
        for(int j=0; j<26; j++) {
            int l, r;
            
            for(l=0; l<s.size(); l++)
                if(s[l] == 'a'+j)
                    break;
            
            r = l;
            int temp = 1;
            
            while(r < s.size()) {
                if(temp < n) {
                    r++;
                    
                    if(r<s.size() && s[r]=='a'+j)
                        temp++;
                }
                
                else {
                    if(temp == n) {
                        rn = min(rn, r-l+1);
                        rx = max(rx, r-l+1);
                    }
                    
                    l++;
                    
                    for(l; l<r; l++)
                        if(s[l] == 'a'+j)
                            break;
                    
                    temp--;
                }
            }
        }
        
        if(rx < 0)
            cout << rx << "\n";
        
        else
            cout << rn << " " << rx << "\n";
    }
    
    return 0;
}