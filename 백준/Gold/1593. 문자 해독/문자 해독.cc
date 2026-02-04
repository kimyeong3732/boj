#include <iostream>

using namespace std;

int alpha[52];
int num[52];

bool check() {
    for(int i=0; i<52; i++)
        if(alpha[i] != num[i])
            return false;
    
    return true;
}

int main() {
    int n, m;
    string input, s;
    
    cin >> n >> m;
    
    cin >> input >> s;
    
    for(int i=0; i<n; i++) {
        if(input[i]>='a' && input[i]<='z')
            alpha[input[i]-'a']++;
        
        else
            alpha[input[i]-'A'+26]++;
    }
    
    int l=-1, r=0;
    int result = 0;
    
    while(r < m) {
        int ir;
        
        if(s[r]>='a' && s[r]<='z')
            ir = s[r] - 'a';
        
        else
            ir = s[r] - 'A' + 26;
        
        num[ir]++;
        
        if(r >= n) {
            l++;
            
            int il;
            
            if(s[l]>='a' && s[l]<='z')
                il = s[l] - 'a';
            
            else
                il = s[l] - 'A' + 26;
            
            num[il]--;
        }
        
        if(check())
            result++;
        
        r++;
    }
    
    cout << result;
    
    return 0;
}