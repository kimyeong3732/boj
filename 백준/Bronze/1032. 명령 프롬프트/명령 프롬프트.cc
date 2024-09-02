#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n;
    vector<string> v;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        
        v.push_back(s);
    }
    
    if(v.size() == 1) {
        cout << v[0];
    }
    else {
        string result = "";
        
        for(int i=0; i<v[0].length(); i++) {
            int j;
            for(j=0; j<v.size(); j++) {
                if(v[j][i] != v[0][i]) {
                    break;
                }
            }
            
            if(j == v.size()) {
                result += v[0][i];
            }
            else {
                result += "?";
            }
        }
        
        cout << result;
    }
    
    return 0;
}