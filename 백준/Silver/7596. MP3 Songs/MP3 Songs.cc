#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    int t = 1;
    
    cin >> n;
    
    while(n > 0) {
        vector<string> v;
        string s;
        
        getline(cin, s);
        
        for(int i=0; i<n; i++) {
            getline(cin, s);
            
            v.push_back(s);
        }
        
        sort(v.begin(), v.end());
        
        cout << t << "\n";
        
        for(int i=0; i<n; i++)
            cout << v[i] << "\n";
        
        t++;
        
        cin >> n;
    }
    
    return 0;
}