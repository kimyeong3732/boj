#include <iostream>
#include <vector>

using namespace std;

int result;
bool alpha[26];
vector<string> v;

void check() {
    int count = 0;
    for(int i=0; i<v.size(); i++) {
        bool state = true;
        
        for(int j=0; j<v[i].size(); j++) {
            if(!alpha[v[i][j] - 'a']) {
                state = false;
                break;
            }
        }
        
        if(state)
            count++;
    }
    
    if(result < count)
        result = count;
}

void find(int index, int size) {
    if(size == 0) {
        check();
        return;
    }
    
    for(int i=index; i<26; i++) {
        if(!alpha[i]) {
            alpha[i] = true;
            find(i+1, size-1);
            alpha[i] = false;
        }
    }
}

int main() {
    int n, k;
    
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        string temp;
        
        cin >> temp;
        
        v.push_back(temp);
    }
    
    if(k >= 5) {
        alpha['a'-'a'] = true;
        alpha['n'-'a'] = true;
        alpha['t'-'a'] = true;
        alpha['i'-'a'] = true;
        alpha['c'-'a'] = true;
        
        find(1, k-5);
    }
    
    cout << result;
    
    return 0;
}