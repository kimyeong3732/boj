#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int result[150];
int state;

void find(vector<string> v, int n, int c) {
    if(c == n) {
        state = 1;
        return;
    }
    
    result[c] = 0;
    if(c==0 || v[c-1].compare(v[c])<0) {
        find(v, n, c+1);
    }
    
    if(state == 1)
        return;
    
    result[c] = 1;
    reverse(v[c].begin(), v[c].end());
    if(c==0 || v[c-1].compare(v[c])<0) {
        find(v, n, c+1);
    }
    reverse(v[c].begin(), v[c].end());
}

int main() {
    int T;
    
    cin >> T;
    
    for(int i=0; i<T; i++) {
        int n;
        vector<string> strs;
        state = 0;
        
        cin >> n;
        
        for(int j=0; j<n; j++) {
            string temp;
            cin >> temp;
            
            strs.push_back(temp);
        }
        
        find(strs, n, 0);
        
        for(int j=0; j<n; j++) {
            cout << result[j];
        }
        cout << '\n';
    }
    
    return 0;
}