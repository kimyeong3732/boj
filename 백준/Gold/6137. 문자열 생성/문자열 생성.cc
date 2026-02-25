#include <iostream>

using namespace std;

int main() {
    int n;
    string s = "";
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string input;
        
        cin >> input;
        
        s += input;
    }
    
    int l=0, r=n-1;
    string result = "";
    
    while(l <= r) {
        if(s[l] < s[r]){
            result += s[l++];
        }
        
        else if(s[l] > s[r]) {
            result += s[r--];
        }
        
        else {
            int ll = l + 1;
            int rr = r - 1;
            bool state = false;
            
            while(ll <= rr) {
                if(s[ll] == s[rr]) {
                    ll++;
                    rr--;
                }
                else {
                    state = true;
                    
                    if(s[ll] < s[rr])
                        result += s[l++];
                    
                    else
                        result += s[r--];
                    
                    break;
                }
            }
            
            if(!state)
                result += s[l++];
        }
    }
    
    for(int i=0; i<n; i++) {
        cout << result[i];
        
        if(i%80 == 79)
            cout << "\n";
    }
    
    return 0;
}