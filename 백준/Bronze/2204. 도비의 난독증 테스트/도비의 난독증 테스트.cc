#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n;
    
    cin >> n;
    
    while(n > 0) {
        vector<string> vs;
        vector<pair<string, int>> va;
        
        for(int i=0; i<n; i++) {
            string s;
            
            cin >> s;
            vs.push_back(s);
            
            string temp = "";
            
            for(int j=0; j<s.size(); j++) {
                
                if(s[j]>='A' && s[j]<='Z')
                    temp += s[j] - 'A' + 'a';
                
                else
                    temp += s[j];
            }
            
            va.push_back(make_pair(temp, i));
        }
        
        sort(va.begin(), va.end());
        
        cout << vs[va[0].second] << "\n";
        
        cin >> n;
    }
}